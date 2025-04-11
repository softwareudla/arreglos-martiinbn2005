#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n_estudiantes = 5, n_materias = 3;
    float calificaciones[5][3];
    char nombres[5][30];
    char materias[3][30];
    int opc;
    int materias_registradas = 0, calificaciones_registradas = 0;

    do
    {
        printf("1. Registrar materias\n");
        printf("2. Registrar calificaciones\n");
        printf("3. Ver promedios por estudiante\n");
        printf("4. Ver promedios por materia\n");
        printf("5. Ver calificaciones mas altas y bajas por estudiante\n");
        printf("6. Ver calificaciones mas altas y bajas por materia\n");
        printf("7. Ver aprobados/reprobados\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        if (opc == 2 && materias_registradas == 0)
        {
            printf("\nERROR. Primero debe registrar las materias (opcion 1)\n\n");
            continue;
        }
        if (opc >= 3 && opc <= 7 && calificaciones_registradas == 0)
        {
            printf("\nERROR. Primero debe registrar las calificaciones (opcion 2)\n\n");
            continue;
        }

        switch (opc)
        {
        case 1:

            printf("\n");

            for (int i = 0; i < n_materias; i++)
            {
                printf("Ingrese el nombre de la materia %d: ", i + 1);
                fflush(stdin);
                fgets(materias[i], 30, stdin);
                materias[i][strcspn(materias[i], "\n")] = '\0';
            }
            materias_registradas = 1;
            printf("\n");

            break;

        case 2:

            printf("\n");

            for (int i = 0; i < n_estudiantes; i++)
            {
                printf("Ingrese el nombre del estudiante %d: ", i + 1);
                fflush(stdin);
                fgets(nombres[i], 30, stdin);
                nombres[i][strcspn(nombres[i], "\n")] = '\0';

                for (int j = 0; j < n_materias; j++)
                {
                    int validacion;
                    float aux_calificacion;

                    do
                    {
                        printf("Ingrese la calificacion de %s para %s: ", materias[j], nombres[i]);
                        validacion = scanf("%f", &aux_calificacion);

                        if (validacion != 1)
                        {
                            printf("Error. Ingrese un numero valido\n");
                            fflush(stdin);
                        }
                        else if (aux_calificacion > 10 || aux_calificacion < 0)
                        {
                            printf("Error. La calificacion debe estar entre 0 y 10\n");
                            validacion = 0;
                        }
                    } while (validacion != 1);

                    calificaciones[i][j] = aux_calificacion;
                }

                printf("\n");
            }
            calificaciones_registradas = 1;

            break;

        case 3:

            printf("\n");

            for (int i = 0; i < n_estudiantes; i++)
            {
                float suma = 0, promedio_estudiante;

                for (int j = 0; j < n_materias; j++)
                {
                    suma += calificaciones[i][j];
                }

                promedio_estudiante = suma / n_materias;

                printf("%s: %.2f\n", nombres[i], promedio_estudiante);
            }
            printf("\n");

            break;

        case 4:

            printf("\n");

            for (int j = 0; j < n_materias; j++)
            {
                float suma = 0, promedio_materia;

                for (int i = 0; i < n_estudiantes; i++)
                {
                    suma += calificaciones[i][j];
                }

                promedio_materia = suma / n_estudiantes;

                printf("%s: %.2f\n", materias[j], promedio_materia);
            }
            printf("\n");

            break;

        case 5:

            for (int i = 0; i < n_estudiantes; i++)
            {
                float max = -1, min = 11;
                int ind_max = 0, ind_min = 0;

                for (int j = 0; j < n_materias; j++)
                {
                    if (calificaciones[i][j] >= max)
                    {
                        max = calificaciones[i][j];
                        ind_max = j;
                    }
                    if (calificaciones[i][j] < min)
                    {
                        min = calificaciones[i][j];
                        ind_min = j;
                    }
                }
                printf("\n%s:\n", nombres[i]);
                printf("Calificacion mas alta: %.2f en %s\n", max, materias[ind_max]);
                printf("Calificacion mas baja: %.2f en %s\n", min, materias[ind_min]);
                printf("\n");
            }
            break;

        case 6:

            for (int j = 0; j < n_materias; j++)
            {
                float max = -1, min = 11;
                int ind_max = 0, ind_min = 0;

                for (int i = 0; i < n_estudiantes; i++)
                {
                    if (calificaciones[i][j] > max)
                    {
                        max = calificaciones[i][j];
                        ind_max = i;
                    }
                    if (calificaciones[i][j] < min)
                    {
                        min = calificaciones[i][j];
                        ind_min = i;
                    }
                }
                printf("\n%s:\n", materias[j]);
                printf("Calificacion mas alta: %.2f de %s\n", max, nombres[ind_max]);
                printf("Calificacion mas baja: %.2f de %s\n", min, nombres[ind_min]);
                printf("\n");
            }
            break;

        case 7:

            printf("\n");

            for (int j = 0; j < n_materias; j++)
            {
                int aprobados = 0, reprobados = 0;
                for (int i = 0; i < n_estudiantes; i++)
                {
                    if (calificaciones[i][j] >= 6)
                        aprobados++;
                    else
                        reprobados++;
                }
                printf("%s - Aprobados: %d, Reprobados: %d\n", materias[j], aprobados, reprobados);
            }
            printf("\n");

            break;

        case 8:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("ERROR. Opcion invalida\n");
            break;
        }
    } while (opc != 8);

    return 0;
}