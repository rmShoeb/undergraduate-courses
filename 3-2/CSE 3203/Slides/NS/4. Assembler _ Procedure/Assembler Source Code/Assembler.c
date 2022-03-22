#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Assembler.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))  

char Pointer_Keywords[4][15] = {"STACKP", "DATAP", "START", "ADDRESSP"};
char ALU_Keywords[13][15] = {"AND", "OR", "XOR", "SHL", "SHR", "ADD", "SUB", "MUL", "ROL", "ROR", "NOT", "CMP", "DIV"};
char Jump_Keywords[13][15] = {"JMP", "JE", "JNE", "JL", "JLE", "JG", "JGE", "JC", "JNC", "JZ", "JNZ", "JMPREG"};
char Registers[8][15] = {"R0","R1","R2","R3","R4","SP","OUTR","INR"};
int stack_pointer=0;
int data_pointer=0;
int start_pointer=0;

// THIS STRUCTURE IS USED TO SAVE ALL THE ASSEMBLY INSTRUCTIONS BASED ON THEIR TYPE
struct machine_code
{
    int op_code_type1; //SAVE 
    int op_code_type2;
    int op1;
    int op2;
    int op3;
    char label[50];
    int machine_instruction[13];
};

// THIS STRUCTURE IS USED TO SAVE ALL LABELS FOUND IN ASSEMBLY CODE
struct label_table
{
    char label[50];
    int line_no;
};

struct machine_code machine_code_lines[100] = {0};
int machine_code_line_no = 0;
struct label_table labels[50] = {0};
int labels_no = 0;

int main()
{
    //INPUT ASSEMBLY PROGRAM FILE WITH COMMENTS
    FILE *input_file = fopen("Program_testing_2.txt", "r");  

    //INPUT ASSEMBLY PROGRAM FILE WITH PROGRAM LINE NO AND WITHOUT COMMENTS. 
    //HELPFUL FOR CPU DEBUGGING
    FILE *assembly_file = fopen("PREPROCESSED_ASSEMBLY.txt", "w"); 

    //ASSEMBLER LOG FILE FOR DEBUGGING PURPOSE
    FILE *log_file = fopen("ASSEMBLER_LOG.txt", "w");

    //OUTPUT MACHINE CODE (BINARY FORMAT)
    FILE *output_binary_file = fopen("OUTPUT_BINARY.txt", "w");

    //OUTPUT MACHINE CODE (HEXADECIMAL FORMT). NEEDED AS ROM IMAGE
    FILE *output_hexadecimal_file = fopen("OUTPUT_HEXADECIMAL.txt", "w");

    //PASS 1 = CONVERT EVERY INSTRUCTION FROM ASSEMBLY TO BINARY WITHOUT CONSIDERING LABELS
    //SAVE ALL THE LABELS IN "label_table" STRUCTURE ARRAY
    //SAVE ALL THE INSTRUCTIONS IN "machine_code" STRUCTURE ARRAY
    //MACHINE CODE OF JUMP INSTRUCTIONS WILL BE IMCOMPLETE
    pass1(input_file, assembly_file, log_file);

    //PASS 2 = ADD ADDRESS TO MACHINE CODE OF JUMP INSTRUCTIONS USING LABEL TABLE
    pass2(log_file);

    //PRINT MACHINE CODE IN A FILE
    code_generation(output_binary_file, output_hexadecimal_file);

    fclose(input_file);
    fclose(log_file);
    fclose(output_binary_file);    
    fclose(output_hexadecimal_file);    

    return 0;
}

void pass1(FILE *input_file, FILE *assembly_file, FILE *log_file)
{
    char tokens[10][10]; 
    int tokens_size;
    char input_line[150];
    int flag_print_in_assembly_file = 0;
    int flag_print_in_assembly_file_label = 0;
    int print_in_assembly_file_line_no = 0;

    while (!feof(input_file))
    {
        fgets(input_line, sizeof(input_line), input_file);
        fprintf(log_file, "%s\n", input_line);
        tokens_size = assembly_program_line_to_tokens(input_line, tokens); //TOKENIZE ASSEMBLY CODE

        if (tokens_size != 0)
        {
            int Pointer_Keyword_Index = check_keyword(tokens[0],Pointer_Keywords, ARRAY_SIZE(Pointer_Keywords)); //CHECK WHETHER FIRST TOKEN IS POINTER KEYWORD
            int Reserved_Keyword_Index = check_keyword(tokens[0], ALU_Keywords, ARRAY_SIZE(ALU_Keywords)); //CHECK WHETHER FIRST TOKEN IS ALU KEYWORDS 
            int Jump_Keyword_Index = check_keyword(tokens[0], Jump_Keywords, ARRAY_SIZE(Jump_Keywords)); //CHECK WHETHER FIRST TOKEN IS JUMP KEYWORDS

            if(Pointer_Keyword_Index>=0)
            {
                if(Pointer_Keyword_Index == 0) stack_pointer = atoi(tokens[1]);
                if(Pointer_Keyword_Index == 1) data_pointer = atoi(tokens[1]);
                if(Pointer_Keyword_Index == 2) start_pointer = atoi(tokens[1]);

                fprintf(log_file,"=============================\n");
                fprintf(log_file, "Stack Pointer = %d\n", stack_pointer);
                fprintf(log_file, "Data Pointer = %d\n", data_pointer);
                fprintf(log_file, "Start Pointer = %d\n", start_pointer);
                fprintf(log_file,"=============================\n");

                print_in_assembly_file_line_no = start_pointer;
            }
            else if(Reserved_Keyword_Index>=0)
            {
                check_Register_and_Immediate_instruction(tokens, tokens_size, log_file);
                flag_print_in_assembly_file = 1;
            }
            else if(Jump_Keyword_Index>=0)
            {
                check_Jump_instruction(tokens, tokens_size, log_file);
                flag_print_in_assembly_file = 1;
            }
            else if(strcmp(tokens[0], "LOAD")==0 || strcmp(tokens[0], "STORE")==0)
            {
                check_Memory_instruction(tokens, tokens_size, log_file);
                flag_print_in_assembly_file = 1;
            }
            else if (strcmp(tokens[0], "PRINT_OUTPUT")==0 || strcmp(tokens[0], "PRINT_CLEAR")==0 || strcmp(tokens[0], "ACCEPT_INPUT")==0)
            {
                check_Print_instruction(tokens, tokens_size, log_file);
                flag_print_in_assembly_file = 1;
            }
            else
            {
               check_JMP_Label(tokens, tokens_size, log_file);
               flag_print_in_assembly_file = 1;
               flag_print_in_assembly_file_label = 1;
            }

            if (flag_print_in_assembly_file==1)
            {
                if(flag_print_in_assembly_file_label!=1)
                {
                    fprintf(assembly_file, "%d ", print_in_assembly_file_line_no);
                    print_in_assembly_file_line_no = print_in_assembly_file_line_no + 1;
                }
    
                for(int i=0; i<tokens_size; i++)
                {
                    fprintf(assembly_file, "%s ", tokens[i]);
                }

                if(flag_print_in_assembly_file_label!=1)
                    fprintf(assembly_file, "\n");

                flag_print_in_assembly_file = 0;
                flag_print_in_assembly_file_label = 0;
            }

        }
    }
}

void pass2(FILE *log_file2)
{
    for(int i=0; i<machine_code_line_no; i++)
    {
        if (strlen(machine_code_lines[i].label)>0)
        {
            struct machine_code machine_code_line = machine_code_lines[i];
            fprintf(log_file2,"############ PASS 2 ###############\n");

            for(int j=0; j<labels_no; j++)
            {
                if (strcmp(machine_code_line.label, labels[j].label)==0)
                {
                    machine_code_line.op1 = labels[j].line_no + start_pointer;
                    fprintf(log_file2, "Labels Label= %s\n", labels[j].label);
                    fprintf(log_file2, "Labels Line No= %d\n", labels[j].line_no);
                }
            }

            decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op1, 6, 7);
            machine_code_lines[i] = machine_code_line;
            print_log(log_file2,NULL, 0, i);
            fprintf(log_file2,"###########################\n");
        }
    }    
}

void code_generation(FILE *output_binary_file, FILE *output_hexadecimal_file)
{
    fprintf(output_hexadecimal_file, "v2.0 raw\n");

    for(int i=0; i<start_pointer; i++)  //Add No Operation until start of program
    {
        fprintf(output_binary_file, "0000000000000\n"); //Add No Operation (ADD R0 R0)
        fprintf(output_hexadecimal_file, "0000 ");  //Add No Operation (ADD R0 R0)
    }

    for(int i=0; i<machine_code_line_no; i++)
    {
        struct machine_code machine_code_line = machine_code_lines[i];

        for (int j = 0; j <=12 ; j++) 
        {

            fprintf(output_binary_file, "%d", machine_code_line.machine_instruction[j]);
            
            if (j != 0 && (j+1) % 4 == 0)
                fprintf(output_hexadecimal_file, "%c", binary_to_hexadecimal(
                                                            machine_code_line.machine_instruction[j-3], 
                                                            machine_code_line.machine_instruction[j-2], 
                                                            machine_code_line.machine_instruction[j-1], 
                                                            machine_code_line.machine_instruction[j]
                                                            ));
            else if (j != 0 && (j+1) == 13)
                fprintf(output_hexadecimal_file, "%c", binary_to_hexadecimal(0, 0, 0, machine_code_line.machine_instruction[j]));
        }
        fprintf(output_binary_file, "\n");
        fprintf(output_hexadecimal_file, " ");
    }
}

int check_keyword(char *token, char keywords[][15], int SIZE)
//MATCH TOKEN WITH KEYWORD ARRAY
{
    for (int i=0; i< SIZE; i++)
    {
        if (strcmp(token, keywords[i])==0)
        {
            return(i);
        }
    }
    return(-1);
}

int assembly_program_line_to_tokens(char *input_line, char tokens[10][10])
//TOKENIZE ASSEMBLY CODE
{
    int i,j;
    j=0;
    int tokens_size = 0;
    int word_flag = 0;
    
    for(i=0;i<=(strlen(input_line));i++)
    {
        if(input_line[i]==' ' || input_line[i]=='\0' || input_line[i]=='\n' || input_line[i]==',')
        {
            if (word_flag == 1)
            {
                tokens[tokens_size][j]='\0';
                tokens_size++;  
                j=0;    
                word_flag = 0;
            }    
        }
        else if(input_line[i]=='#')
        {
            //condition for comments
            break;
        }
        else
        {
            tokens[tokens_size][j]=input_line[i];
            j++;
            word_flag = 1;
        }
    }
    return(tokens_size);
}

void check_Register_and_Immediate_instruction(char tokens[10][10], int tokens_size, FILE *log_file)
//CONVERT REGISTER/IMMEDIATE INSTRUCTION TO MACHINE CODE AND SAVE IT TO MACHINE CODE TABLE
{
    struct machine_code machine_code_line = machine_code_lines[machine_code_line_no];

    int Reserved_Keyword_Index = check_keyword(tokens[0], ALU_Keywords, ARRAY_SIZE(ALU_Keywords));        
    machine_code_line.op_code_type2 = Reserved_Keyword_Index;

    int Registers1_Index = check_keyword(tokens[1], Registers, ARRAY_SIZE(Registers));
    machine_code_line.op1 = Registers1_Index; 

    int Registers2_Index = check_keyword(tokens[2], Registers, ARRAY_SIZE(Registers));
    if(Registers2_Index>=0)
    {
        machine_code_line.op2 = Registers2_Index;
        machine_code_line.op_code_type1 = 0;                    
        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op2, 9, 3);
    }
    else
    {
        machine_code_line.op2 = atoi(tokens[2]);
        machine_code_line.op_code_type1 = 1;                                        
        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op2, 9, 4);
    }

    int starting_position = 0;
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type1, starting_position, 2);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type2, starting_position, 4);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op1, starting_position, 3);

    machine_code_lines[machine_code_line_no] = machine_code_line;

    print_log(log_file,tokens, tokens_size, machine_code_line_no);
    machine_code_line_no = machine_code_line_no + 1;
}

void check_Jump_instruction(char tokens[10][10], int tokens_size, FILE *log_file)
//CONVERT JUMP INSTRUCTION TO MACHINE CODE AND SAVE IT TO MACHINE CODE TABLE
{
    struct machine_code machine_code_line = machine_code_lines[machine_code_line_no];

    int Jump_Keyword_Index = check_keyword(tokens[0], Jump_Keywords, ARRAY_SIZE(Jump_Keywords));

    machine_code_line.op_code_type1 = 2;
    machine_code_line.op_code_type2 = Jump_Keyword_Index; 

    if (Jump_Keyword_Index!=11)               
        strcpy(machine_code_line.label, tokens[1]);
    else
    {
        int Registers1_Index = check_keyword(tokens[1], Registers, ARRAY_SIZE(Registers));
        machine_code_line.op1 = Registers1_Index;
        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op1, 6, 3);    
    }

    int starting_position = 0;
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type1, starting_position, 2);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type2, starting_position, 4);

    machine_code_lines[machine_code_line_no] = machine_code_line;
    
    print_log(log_file,tokens, tokens_size, machine_code_line_no);
    machine_code_line_no = machine_code_line_no + 1;
}

void check_Memory_instruction(char tokens[10][10], int tokens_size, FILE *log_file)
//CONVERT MEMORY INSTRUCTION TO MACHINE CODE AND SAVE IT TO MACHINE CODE TABLE
{
    int op_code_type2_for_STORE = 0;
    if (strcmp(tokens[0], "STORE")==0)
    {
        char temp[30] = {0};
        strcpy(temp, tokens[1]);
        strcpy(tokens[1],tokens[2]);
        strcpy(tokens[2],temp);

        op_code_type2_for_STORE = 3;  //OP_CODE_TYPE2 WILL BE ADDED BY 3 TO MAKE IT STORE INSTRUCTION
    }
    
    int starting_position = 0;
    struct machine_code machine_code_line = machine_code_lines[machine_code_line_no];
    machine_code_line.op_code_type1 = 3; 

    int Registers1_Index = check_keyword(tokens[1], Registers, ARRAY_SIZE(Registers));
    machine_code_line.op1 = Registers1_Index; 

    char temp_operand[30]={};
    strncpy(temp_operand, tokens[2]+1, strlen(tokens[2])-2);
    
    int Registers2_Index = check_keyword(temp_operand, Registers, ARRAY_SIZE(Registers));

    if(Registers2_Index>=0)
    {
        machine_code_line.op2 = Registers2_Index;
        machine_code_line.op_code_type2 = 1 + op_code_type2_for_STORE;

        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op2, 9, 3);
    }
    else if(strchr(temp_operand,'+')!=0)
    {
        char *token1 = strtok(temp_operand, "+");
        char *token2 = strtok(NULL, "+");
        int Registers2_Index = check_keyword(token1, Registers, ARRAY_SIZE(Registers));
        int Displacement = atoi(token2);

        if (Registers2_Index > 3 || Displacement > 3)
        {
            printf("In LOAD/STORE instruction using Based with Displacement Mode (LOAD RA, [RB+X] / STORE [RB+X], RA), RB must be within R0-R3 and X must be within between 0-3.\n");
            printf("<========EXITING THE PROGRAM.==========>\n");
            FILE *output_binary_file = fopen("OUTPUT_BINARY.txt", "w");
            FILE *output_hexadecimal_file = fopen("OUTPUT_HEXADECIMAL.txt", "w");
            fclose(output_binary_file);    
            fclose(output_hexadecimal_file);
            exit(-1);
        }

        machine_code_line.op2 = Registers2_Index;
        machine_code_line.op3 = Displacement;
        machine_code_line.op_code_type2 = 2 + op_code_type2_for_STORE;

        starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op2, 9, 2);
        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op3, starting_position, 2);
    }
    else
    {
        machine_code_line.op2 = atoi(temp_operand);
        machine_code_line.op_code_type2 = 0 + op_code_type2_for_STORE;

        decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op2, 9, 4);
    }
    
    starting_position = 0;
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type1, starting_position, 2);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type2, starting_position, 4);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op1, starting_position, 3);

    machine_code_lines[machine_code_line_no] = machine_code_line;

    print_log(log_file,tokens, tokens_size, machine_code_line_no);
    machine_code_line_no = machine_code_line_no + 1;
}


void check_Print_instruction(char tokens[10][10], int tokens_size, FILE *log_file)
//CONVERT IO INSTRUCTION TO MACHINE CODE AND SAVE IT TO MACHINE CODE TABLE
{
    struct machine_code machine_code_line = machine_code_lines[machine_code_line_no];
    machine_code_line.op_code_type1 = 3; 

    if (strcmp(tokens[0], "ACCEPT_INPUT")==0)
        machine_code_line.op_code_type2 = 13;     
    else if (strcmp(tokens[0], "PRINT_OUTPUT")==0)
        machine_code_line.op_code_type2 = 14; 
    else if (strcmp(tokens[0], "PRINT_CLEAR")==0)
        machine_code_line.op_code_type2 = 15;     

    int starting_position = 0;
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type1, starting_position, 2);
    starting_position = decimalToBinary(machine_code_line.machine_instruction, machine_code_line.op_code_type2, starting_position, 4);

    machine_code_lines[machine_code_line_no] = machine_code_line;
    print_log(log_file,tokens, tokens_size, machine_code_line_no);
    machine_code_line_no = machine_code_line_no + 1;
}

void check_JMP_Label(char tokens[10][10], int tokens_size, FILE *log_file)
//CHECK WHETHER ASSEMBLY CODE HAS LABEL IN IT
{
    int last_index_of_string = strlen(tokens[0])-1;

    if(tokens[0][last_index_of_string]==':')
    {
        char temp_string[50] = {};
        strncpy(temp_string, tokens[0], last_index_of_string);
        strcpy(labels[labels_no].label, temp_string);
        labels[labels_no].line_no = machine_code_line_no;

        fprintf(log_file,"=============================\n");
        for(int i=0; i < tokens_size;i++)
        {
            fprintf(log_file, "%s\n", tokens[i]);
        }
        fprintf(log_file, "Labels no = %d\n", labels_no);
        fprintf(log_file, "Label = %s\n", labels[labels_no].label);
        fprintf(log_file, "Line no = %d\n", labels[labels_no].line_no);
        fprintf(log_file, "=============================\n");

        labels_no = labels_no + 1;
    }
}

void print_log(FILE *log_file, char tokens[10][10], int tokens_size, int machine_code_line_no)
//SAVE LOG INFO OF ASSEMBLER
{
    struct machine_code machine_code_line = machine_code_lines[machine_code_line_no];

    fprintf(log_file,"=============================\n");
    for(int i=0; i < tokens_size;i++)
    {
        fprintf(log_file, "%s\n",tokens[i]);
    }

    fprintf(log_file, "Machine code line no = %d\n", machine_code_line_no);
    fprintf(log_file, "OP_CODE_TYPE1 = %d\n", machine_code_line.op_code_type1);
    fprintf(log_file, "OP_CODE_TYPE2 = %d\n", machine_code_line.op_code_type2);
    fprintf(log_file, "OP1 = %d\n", machine_code_line.op1);
    fprintf(log_file, "OP2 = %d\n", machine_code_line.op2);
    fprintf(log_file, "OP3 = %d\n", machine_code_line.op3);
    fprintf(log_file, "LABEL = %s\n", machine_code_line.label);
    fprintf(log_file, "MACHINE INSTRUCTION = "); 
    for (int j = 0; j <=12 ; j++)
        fprintf(log_file, "%d", machine_code_line.machine_instruction[j]);
    fprintf(log_file, "\n");

    fprintf(log_file, "=============================\n");
}

char binary_to_hexadecimal (int first_digit, int second_digit, int third_digit, int fourth_digit)
//CONVERT 4-BIT BINARY TO EQUIVALENT HEXA DECIMAL
{
    if (first_digit == 0 && second_digit == 0 && third_digit == 0 && fourth_digit == 0) return('0');
    if (first_digit == 0 && second_digit == 0 && third_digit == 0 && fourth_digit == 1) return('1');
    if (first_digit == 0 && second_digit == 0 && third_digit == 1 && fourth_digit == 0) return('2');
    if (first_digit == 0 && second_digit == 0 && third_digit == 1 && fourth_digit == 1) return('3');
    if (first_digit == 0 && second_digit == 1 && third_digit == 0 && fourth_digit == 0) return('4');
    if (first_digit == 0 && second_digit == 1 && third_digit == 0 && fourth_digit == 1) return('5');
    if (first_digit == 0 && second_digit == 1 && third_digit == 1 && fourth_digit == 0) return('6');
    if (first_digit == 0 && second_digit == 1 && third_digit == 1 && fourth_digit == 1) return('7');

    if (first_digit == 1 && second_digit == 0 && third_digit == 0 && fourth_digit == 0) return('8');
    if (first_digit == 1 && second_digit == 0 && third_digit == 0 && fourth_digit == 1) return('9');
    if (first_digit == 1 && second_digit == 0 && third_digit == 1 && fourth_digit == 0) return('A');
    if (first_digit == 1 && second_digit == 0 && third_digit == 1 && fourth_digit == 1) return('B');
    if (first_digit == 1 && second_digit == 1 && third_digit == 0 && fourth_digit == 0) return('C');
    if (first_digit == 1 && second_digit == 1 && third_digit == 0 && fourth_digit == 1) return('D');
    if (first_digit == 1 && second_digit == 1 && third_digit == 1 && fourth_digit == 0) return('E');
    if (first_digit == 1 && second_digit == 1 && third_digit == 1 && fourth_digit == 1) return('F');

    return(-1);
}

int decimalToBinary(int *machine_instruction, int number, int starting_position, int size) 
//CONVERT TO DECIMAL NUMBER TO BINARY NUMBER
{
    if(number == -1)
    {
        printf("Error in Register value or JMP instruction at line %d: Register must be within (R0-R4).\n <========EXITING THE PROGRAM.==========>\n", machine_code_line_no);
        FILE *output_binary_file = fopen("OUTPUT_BINARY.txt", "w");
        FILE *output_hexadecimal_file = fopen("OUTPUT_HEXADECIMAL.txt", "w");
        fclose(output_binary_file);    
        fclose(output_hexadecimal_file);
        exit(-1);
    }

    int i = 0;
    int binary[30] = {0}; 
    while (number > 0) 
    {
        binary[i] = (number % 2); 
        number = number / 2; 
        i++; 
    } 
  
    int k = i-1;
    int j;
    for (j = starting_position+size-i; j <= starting_position+size-1; j++) 
    {
        machine_instruction[j] = binary[k];
        k--;
    }
    return(j);
} 
