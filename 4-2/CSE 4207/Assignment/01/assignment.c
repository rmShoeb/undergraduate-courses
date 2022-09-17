#include <stdio.h>

int main(void)
{
    int Vt = 1; // considering enhancement mode NMOS transistor, page-12
    int Vgs = 0;
    int Vds = 0;
    int Ids = 0;

    /**
     * for n-channel enhancement (from page-19)
     * W = L
     * eun/D = 30uA/V^2
     * Hence,
     * eWun/LD = 30uA/V^2 = 30*10^-6 A/V^2
    **/
   const int constant = 30;

   FILE *fptr;
   fptr = fopen("output.csv", "w");
   fprintf(fptr, "Vgs,Vds,Ids\n");

    for(int i; i<5; i++){
        printf("Enter Vgs: ");
        scanf("%d", &Vgs);
        for(Vds=0; Vds<=30; Vds++){
            if (Vds < (Vgs-Vt)) //resistive region
            {
                Ids = constant*(Vgs-Vt)*Vds;
            }
            else // saturation 
            {
                Ids = (constant/2)*(Vgs-Vt)*(Vgs-Vt);
            }
            // printf("%d\t%d\t%d\n", Vgs, Vds, Ids);
            fprintf(fptr, "%d,%d,%d\n", Vgs, Vds, Ids);
        }
    }

    fclose(fptr);

    return 0;
}
