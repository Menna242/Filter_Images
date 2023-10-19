/*
   * FCAI – OOP Programming – 2023 - Assignment 1

    Program Name: CS213-2023-20221167-20220151-20221032-A1-Part1.cpp

    Last Modification Date: 9/10/2023

    Author1 and ID : Sara Nabil Ali Hassan , id: 20220151
    ,email: saranabilali19@gmail.com

    Author2 and ID : Menna Essam Salah El-Din Mohamed , id: 20221167
    ,email:menaesam14@gmail.com

    Author3 and ID : Aya Mohamed Saber Mahmoud ,Id: 20221032
    ,email: aya44saber@gmail.com


    Purpose: How to make changes to images such as image processing software (Photoshop)






*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];
unsigned char image4[SIZE][SIZE][RGB];
unsigned char imageNew[SIZE][SIZE][RGB];
void loadImage ();
void Black_white();
void load1Image ();
void saveImage ();
void select_filter ();
void marge_image();
void Darken_Lighten();
void flip();
void Rotate();
void Invert();
void shrank();
void crop();
void plur();
void Skew();
void Detect_Image_Edges();
void Enlarge_image();
void Mirror_Image() ;
void Shuffle_Image();




int main()
{
    cout<<"Ahlan ya user ya habibi "<<'\n';
    loadImage();
    select_filter();
  


    return 0;

}

string s;
int angle;
int k;
void select_filter(){
    cout<<"Please select a filter to apply or 0 to exit: "<<'\n';
    cout<<"1- Black & White Filter"<<'\n';
    cout<<"2- Invert Filter"<<'\n';
    cout<<"3- Merge Filter"<<'\n';
    cout<<"4- Flip Image"<<'\n';
    cout<<"5- Rotate Image"<<'\n';
    cout<<"6- Darken and Lighten"<<'\n';
    cout<<"7- Detect Image Edges"<<'\n';
    cout<<"8- Enlarge Image"<<'\n';
    cout<<"9- Shrink Image"<<'\n';
    cout<<"10- Mirror 1/2 Image"<<'\n';
    cout<<"11- Shuffle Image"<<'\n';
    cout<<"12- Blur Image"<<'\n';
    cout<<"13- Crop Image"<<'\n';
    cout<<"14- Skew Image"<<'\n';
    cout<<"15- Save the image to a file"<<'\n';
    cout<<" 0- Exit"<<'\n';

    int n;
    cin>>n;
    if(n==1){
        Black_white();

    }
    if(n==2){
        Invert();

    }
    if(n==3){
        marge_image();
    }
    if(n==4){
        cout<<"Please Choose Horizontally Or Vertically : ";
        cin>>s;
        flip();
    }
    if(n==5){
        cout<<"Please Choose The Angle (90) or (180) or (270) : ";
        cin>>angle;
        Rotate();
    }
    if(n==6){
        cout<<"Please choose Darken or Lighten : ";
        cin>>s;
        Darken_Lighten();
    }
    if (n==7){
        Detect_Image_Edges();
    }
    if (n==8){
        cout<<"Please enter the quarter : ";
        Enlarge_image();
    }
    if(n==9){
        cout << " Enter the size of shrink you want (2) or (3) or (4) :  ";
        shrank();

    }
    if(n==10){
        cout<<"Do you want the mirror to reflect the left,right,upper,or lower : ";
        Mirror_Image() ;
    }
    if(n==11){
        cout<<"New order of quarters : ";
        Shuffle_Image();

    }
    if(n==12){
        plur();
    }
    if(n==13){
        crop();
    }
    if(n==14){
        cout << "Do you want vertically or horizontally : ";
        Skew();
    }
    if(n==15){
        saveImage();

    }

    if(n==0){
        return ;
    }
    select_filter();

}


void loadImage () {
    char imageFileName[100];

    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

void load1Image () {
    char imageFileName[100];

    cout << "Enter the source image2 file name: ";
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);
}

void saveImage () {
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

void Black_white() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; ++k) {
                int ave=(image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
                if (ave > 127)
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0;
        }
    }}
    saveImage();
}

void Invert(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}

//-----------------------------------------------------------------

void marge_image(){
    load1Image();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                image[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2;
            }



        }
    }



}
void flip(){
    if(s[0]=='V'){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k <RGB ; ++k) {


                swap(image[i][j][k],image[SIZE-1-i][j][k]);
            }
        }}
    }
    else{

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                for (int k = 0; k < RGB; ++k) {


                swap(image[i][j][k],image[i][SIZE-1-j][k]);
            }
        }}
    }

}


void Rotate(){
    if(angle==90){
        int k=0;
        for (int i = SIZE-1; i >= 0; --i) {
            for (int j = SIZE-1; j >=0; --j) {
                for (int l = 0; l <RGB ; ++l) {
                    imageNew[k][j][l] = image[j][i][l];
                }
            }
            k++;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int l = 0; l < RGB; ++l) {

                    image[i][j][l] = imageNew[i][j][l];
                }
            }
        }
    }

    else if(angle==180){
        int k=0,m=0;
        for (int i = SIZE-1; i >= 0; --i) {
            for (int j = SIZE-1; j >=0; --j) {
                for (int l = 0; l < RGB; ++l) {
                    imageNew[k][m][l] = image[i][j][l];

                }
                m++;

            }
            k++;
            m=0;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int l = 0; l < RGB; ++l) {
                    image[i][j][l] = imageNew[i][j][l];
                }
            }
        }

    }


    else if(angle==270){
        int m=0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = SIZE-1; j >=0; --j) {
                for (int l = 0; l < RGB; ++l) {
                    imageNew[i][m][l] = image[j][i][l];
                }
                m++;
            }
            m=0;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int l = 0; l < RGB; ++l) {
                    image[i][j][l] = imageNew[i][j][l];
                }
            }
        }

    }

}


void Darken_Lighten() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k <3 ; ++k) {
                if(s[0]=='D'){
                    image[i][j][k]=image[i][j][k]/2.5;
                }
                else{
                    image[i][j][k]=image[i][j][k]+(255-image[i][j][k])/2;
                }
            }
        }
    }

}



void Detect_Image_Edges() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                int ave = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / 3;
                if (ave > 127)
                    image[i][j][k] = 255;
                else
                    image[i][j][k] = 0;
            }
        }
    }
    int av = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                av += image[i][j][k];

            }}
    }
    av = av / (256 * 256 *256);

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            for (int k = 0; k < RGB; ++k) {
                int current = image[i][j][k];
                int down = image[i + 1][j][k];
                int left = image[i][j - 1][k];
                if (::abs(current - down) > av || ::abs(current - left) > av)
                    imageNew[i][j][k] = 0;
                else
                    imageNew[i][j][k] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] = imageNew[i][j][k];
            }
        }
    }
}



void Enlarge_image(){
    cout<<"Please enter the quarter : ";
    int quarter; cin>>quarter;
    if(quarter==1){
        int k=0,y=1,l=0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; ++j) {
                for (int m = 0; m < RGB; ++m) {
                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];

                }
                k++;
                for (int m = 0; m < RGB; ++m) {
                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];

                }
                k++;

            }
            k=0;
            l+=2;
            y+=2;
        }

    }
    else if(quarter==2){
        int k=0,y=1,l=0;
        for (int i = 0; i <128 ; ++i) {
            for (int j = 128; j <SIZE ; ++j) {
                for (int m = 0; m < RGB; ++m) {


                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];
                }

                    k++;
                for (int m = 0; m < RGB; ++m) {
                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];
                }
                k++;


            }
            k=0;
            l+=2;
            y+=2;

        }

    }
    else if(quarter==3){
        int k=0,y=1,l=0;
        for (int i = 128; i <SIZE ; ++i) {
            for (int j = 0; j < 128; ++j) {
                for (int m = 0; m <RGB ; ++m) {

                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];
                }
                    k++;
                for (int m = 0; m <RGB ; ++m) {
                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];
                }
                k++;

            }

            k=0;
            l+=2;
            y+=2;

        }

    }
    else if(quarter==4){
        int k=0,y=1,l=0;
        for (int i = 128; i <SIZE ; ++i) {
            for (int j = 128; j <SIZE ; ++j) {
                for (int m = 0; m <RGB ; ++m) {
                    imageNew[l][k][m] = image[i][j][m];
                    imageNew[y][k][m] = image[i][j][m];
                }
                    k++;
                for (int m = 0; m < RGB; ++m) {
                    imageNew[l][k][m]= image[i][j][m];
                    imageNew[y][k][m]= image[i][j][m];
                }
                k++;
            }
            k=0;
            l+=2;
            y+=2;

        }


    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] = imageNew[i][j][k];
            }
        }
    }
}

void shrank() {
    int nn;
    cin>>nn;

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j][k]=255;
        }

    }

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                if(nn==2){
                    image3[i/2][j/2][k]=image[i][j][k];
                }
                else if(nn==3){
                    image3[i/3][j/3][k]=image[i][j][k];

                }
                else {
                    image3[i/4][j/4][k]=image[i][j][k];
                }

            }

        }

    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {
                image[i][j][k]=image3[i][j][k];
            }


        }

    }




}

void Shuffle_Image(){
    int l=4,n,m=0;
    while(l--){
        cin>>n;
        if(m==0){
            int k=0,d=0;
            if(n==1){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][j][i1] = image[i][j][i1];
                        }
                    }
                }
                m++;
            }
            else if(n==2){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {

                            imageNew[i][k][i1] = image[i][j][i1];
                        }
                        k++;
                    }
                    k=0;
                }
                m++;
            }
            else if(n==3){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[d][j][i1]=image[i][j][i1];

                        }
                    }
                    d++;
                }
                m++;
            }
            else if(n==4){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[d][k][i1]=image[i][j][i1];

                        }
                        k++;
                    }
                    k=0;
                    d++;
                }
                m++;
            }
        }
            //   ------------------------------------
        else if(m==1){
            int k,d=0;
            if(n==1){
                k=128;
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==2){
                k=128;
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==3){
                k=128;
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[d][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=128;
                    d++;
                }
                m++;
            }
            else if(n==4){
                k=128;
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[d][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=128;
                    d++;
                }
                m++;
            }
        }
            //------------------------------------
        else if (m==2){
            int d=128,k=0;
            if(n==1){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 <RGB ; ++i1) {
                            imageNew[d][j][i1]=image[i][j][i1];

                        }
                    }
                    d++;
                }
                m++;
            }
            else if(n==2){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 <RGB ; ++i1) {
                            imageNew[d][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=0;
                    d++;
                }
                m++;
            }
            else if(n==3){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][j][i1]=image[i][j][i1];
                        }
                    }
                }
                m++;
            }
            else if(n==4){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][k][i1]=image[i][j][i1];
                        }
                        k++;
                    }
                    k=0;
                }
                m++;
            }
        }

        else if(m==3){
            int d=128,k=128;
            if(n==1){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[d][k][i1]=image[i][j][i1];

                        }
                        k++;

                    }
                    d++;
                    k=128;

                }
                m++;
            }
            else if(n==2){
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 <RGB ; ++i1) {
                            imageNew[d][j][i1]=image[i][j][i1];

                        }
                    }
                    d++;
                }
                m++;
            }
            else if(n==3){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][k][i1]=image[i][j][i1];

                        }
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==4){
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        for (int i1 = 0; i1 < RGB; ++i1) {
                            imageNew[i][j][i1]=image[i][j][i1];

                        }
                    }
                }
                m++;
            }
        }
    }

    if(m==4){
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k]=imageNew[i][j][k];

                }
            }
        }
   }

}

void plur(){

    for(int l=0 ; l<20 ; l++){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; ++k) {
                    if(i==0&&j==0){
                        image3[i][j][k]=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k])/4;
                    }
                    if(i==0&&j==SIZE-1){
                        image3[i][j][k]=(image[i][j][k]+image[i][j-1][k]+image[i+1][j][k]+image[i+1][j-1][k])/4;
                    }
                    if(i==SIZE-1&&j==0){
                        image3[i][j][k]=(image[i][j][k]+image[i-1][j][k]+image[i][j+1][k]+image[i-1][j+1][k])/4;
                    }
                    if(i==SIZE-1&&j==SIZE-1){
                        image3[i][j][k]=(image[i][j][k]+image[i][j-1][k]+image[i-1][j][k]+image[i-1][j-1][k])/4;
                    }
                    if(i>0&&j==0){
                        image3[i][j][k]=(image[i][j][k]+image[i-1][j][k]+image[i+1][j][k]+image[i][j+1][k]+image[i-1][j+1][k]+image[i+1][j+1][k])/6;

                    }
                    if(i==0&&j>0){
                        image3[i][j][k]=(image[i][j][k]+image[i][j+1][k]+image[i][j-1][k]+image[i+1][j][k]+image[i+1][j+1][k]+image[i+1][j-1][k])/6;

                    }
                    if(i==SIZE-1&&j>0){
                        image3[i][j][k]=(image[i][j][k]+image[i][j+1][k]+image[i][j-1][k]+image[i-1][j][k]+image[i-1][j+1][k]+image[i-1][j-1][k])/6;

                    }
                    if(i>0&&j==SIZE-1){
                        image3[i][j][k]=(image[i][j][k]+image[i-1][j][k]+image[i+1][j][k]+image[i][j-1][k]+image[i-1][j-1][k]+image[i+1][j-1][k])/6;

                    }
                    if(i>0&&i<SIZE-1&&j>0&&j<SIZE-1){
                        image3[i][j][k]=(image[i][j][k]+image[i-1][j][k]+image[i+1][j][k]+image[i][j-1][k]+image[i][j+1][k]+image[i-1][j-1][k]+image[i-1][j+1][k]+image[i+1][j-1][k]+image[i+1][j+1][k])/9;
                    }

                }

            }


        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image[i][j][k]=image3[i][j][k];
                }


            }

        }





    }






}

void crop() {

    int n=0,l=0;
    int x,y,w,m;
    cout<<"Enter the point (x,y) you want to start from : ";
    cin>>x>>y; cout<<endl;
    cout<<"Enter the Length and width you want : ";
    cin>>w>>m;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < 3; ++k) {
                image3[i][j][k]=255;

            }
        }

    }

    for (int i = x; i < m ; i++) {
        for (int j = y; j < w; j++) {
            for (int k = 0; k <3 ; ++k) {
                image3[n][l][k]=image[i][j][k];
            }

            l++;
        }
        n++;
        l=0;

    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k <3 ; ++k) {
                image[i][j][k]=image3[i][j][k];

            }

        }

    }




}


void Mirror_Image() {

    if (s == "left") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][SIZE - 1 - j][k] = image[i][j][k];
                }
            }
        }
    } else if (s == "right") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; ++k) {


                    image[i][j][k] = image[i][SIZE - 1 - j][k];
                }
            }
        }
    } else if (s == "lower") {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k] = image[SIZE - 1 - i][j][k];
                }
            }
        }
    } else {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {
                    image[SIZE - 1 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
}

void Skew() {

    string h;
    cin>>h;
    if(h[0]=='v'){
        cout<<"Enter an angle: ";
        float n; cin>>n;
        n=90-n;
        n=(n*22)/(7*180);
        n=tan(n);
        int x=256/(1+(1/n));
        int y=x;
        x=(256/x);


        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; ++k) {
                    image3[i][j][k]=250;

                }
            }

        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k <3 ; ++k) {
                    image3[i][j][k] = image[i][j*x][k];
                }

            }
        }
        double step=256-y;
        double move=step/256;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; ++k) {
                    image4[i-1][j+int(step)][k]=image3[i][j][k];
                }

            }
            step-=move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k <3 ; ++k) {
                    image[i][j][k]=image4[i][j][k];
                }

            }

        }


    }
    else{
        cout<<"Enter an angle: ";
        float angle; cin>>angle;
        angle=angle/180/7*22;
        angle=tan(angle);
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k <RGB ; ++k) {

                    image4[i][j][k]=255;}}}
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k <RGB; ++k) {


                    image3[i][j][k]=255;}}}

        for (int i = 0; i < SIZE*(1-angle); i++){
            for (int j = 0; j < SIZE; j++){
                for (int k = 0; k < RGB; ++k) {


                    image3[i][j][k] = image[int(i / (1 - angle))][j][k];}}}

        for (int i = 0; i <SIZE ; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k <RGB ; ++k) {

                    image4[i+int(angle*(256-j))][j][k]=image3[i][j][k];
                }}}

        for (int i = 0; i <SIZE ; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k <RGB ; ++k) {


                    image[i][j][k]= image4[i][j][k];}}}}


}

