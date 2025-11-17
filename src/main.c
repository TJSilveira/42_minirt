#include "../includes/minirt.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    int image_width = 256;
    int image_heigth = 256;

    // vec3 v1 = {{1.0,2.0,3.0}};
    // vec3 v2 = {{5.0,5.0,5.0}};
    // ray r = {{1.0,0.0,0.0},{1.0,2.0,3.0},};
    
    // vec3_add_2inst(&v1, &v2);

    // printf("%f.%f.%f\n", v1.e[0], v1.e[1], v1.e[2]);
    ft_putstr_fd("P3\n", STDOUT_FILENO);
    ft_putnbr_fd(image_width, STDOUT_FILENO);
    ft_putstr_fd(" ", STDOUT_FILENO);
    ft_putnbr_fd(image_heigth, STDOUT_FILENO);
    ft_putstr_fd("\n255\n", STDOUT_FILENO);

    int j = 0;
    while(j < image_heigth)
    {
        int i = 0;
        while(i < image_width)
        {
            color3 color;
            color.e[0] = (double)(i) / (double)(image_width - 1);
            color.e[1] = (double)(j) / (double)(image_heigth - 1);
            color.e[2] = 0.0;
            write_color(&color);
            ft_putstr_fd("\n", STDOUT_FILENO);

            i++;
        }
        j++;
    }

    return(0);
}