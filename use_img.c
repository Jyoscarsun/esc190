# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "c_img.c"

int main(){
    char *image = "image.bin";
    struct rgb_img *im;
    read_in_img(&im, image);

    double intensity = 1.2;
    int count = 1;
    while(count <= 5){
        for(int i = 0; i < im->height; i++){
            for(int j = 0; j < im->width; j++){
                int r = get_pixel(im, i, j, 0) * intensity;
                int g = get_pixel(im, i, j, 1) * intensity;
                int b = get_pixel(im, i, j, 2) * intensity;
                if(r > 255){
                    r = 255;
                }
                if(g > 255){
                    g = 255;
                }
                if(b > 255){
                    b = 255;
                }
                set_pixel(im, i, j, r, g, b);
            }
        }
        char str[80];
        sprintf(str, "image%d.bin", count);
        write_img(im, str);
        intensity += 0.2;
        count++;
    }
}