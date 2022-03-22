
void pass1(FILE *input_file, FILE *assembly_file, FILE *log_file);
void pass2();
void code_generation();

void check_Register_and_Immediate_instruction(char tokens[10][10], int tokens_size, FILE *log_file);
void check_Jump_instruction(char tokens[10][10], int tokens_size, FILE *log_file);
void check_Memory_instruction(char tokens[10][10], int tokens_size, FILE *log_file);
void check_Print_instruction(char tokens[10][10], int tokens_size, FILE *log_file);
void check_JMP_Label(char tokens[10][10], int tokens_size, FILE *log_file);

int check_keyword(char *token, char keywords[][15], int SIZE);
int assembly_program_line_to_tokens(char *input_line, char tokens[10][10]);
void print_log(FILE *log_file, char tokens[10][10], int tokens_size, int machine_code_line_no);

int decimalToBinary(int *machine_instruction, int number, int starting_position, int size) ;
char binary_to_hexadecimal (int first_digit, int second_digit, int third_digit, int fourth_digit);
