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
unsigned char image[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char imageNew[SIZE][SIZE];


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
void skew();
void edge();
void Enlarge_image();
void Mirror_image();
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
        cout<<"Please choose Darken or Lighten  : ";
      cin>>s;
        Darken_Lighten();
    }
    if (n==7){
        edge();
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
        Mirror_image();
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
        skew();
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
    readGSBMP(imageFileName, image);
}

void load1Image () {
    char imageFileName[100];

    cout << "Enter the source image2 file name: ";
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}

void saveImage () {
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void Black_white() {
    /*
    It converts the image from gray to black and white by examining each pixel.
    If the value is greater than 127, it is converted to 255 (white),
    and if it is less than or equal to 127, it is converted to 0(black)
    */
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;


        }
    }

}

void Invert(){
    /* we  choose 255 Because the largest pixel color is 255(white color)
   ,so we donot have (-) number ==>
   if(image[i][j] =255  --> new image[i][j]=255-255=0  is black
   if(image[i][j] =0  --> new image[i][j]=255-0=255  is white
  if(image[i][j] =125  --> new image[i][j]=255-125=130  is Degree of grey
  */

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j]=255-image[i][j];
        }
    }

}


void marge_image(){
    load1Image();  // to take from user second image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

                image[i][j] = (image[i][j] + image2[i][j]) / 2; //To make the ratio of the first and second image equal
            // in one pixel

        }
    }


}

void flip(){
    /*
    choose between mirroring an image vertically or horizontally. If "vertically" is chosen,
    it swaps corresponding rows of the image array, if any other input is given,
    it swaps corresponding columns to mirror the imagehorizontally.
    */
    if(s[0]=='V'){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE; j++) {
                swap(image[i][j],image[SIZE-1-i][j]);
            }
        }
    }
    else{

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                swap(image[i][j],image[i][SIZE-1-j]);
            }
        }
    }

}


void Rotate(){
    /*I will start from the last column and every index in the rows from last to first
        will be recorded in the pixel in the new array from the last to the first column
        of the same row( row starts by 0) with these values

        */
    if(angle==90){
        int k=0;
        for (int i = SIZE-1; i >= 0; --i) {
            for (int j = SIZE-1; j >=0; --j) {
                imageNew[k][j] =image[j][i];

            }
            k++;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=imageNew[i][j];
            }
        }
    }

    else if(angle==180){
        /*I will start from the last row and every index in the columns from last to first
        will be recorded in the pixel in the new array from the first to the last column
        of the same row( row starts by 0) with these values
        */
        int k=0,m=0;
        for (int i = SIZE-1; i >= 0; --i) {
            for (int j = SIZE-1; j >=0; --j) {
                imageNew[k][m] =image[i][j];
                m++;

            }
            k++;
            m=0;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=imageNew[i][j];
            }
        }

    }


    else if(angle==270){
        /*I will start from the first row and every index in the columns from last to first
       will be recorded in the pixel in the new array from the first( column starts by 0) to the last column
       of the same row( row starts by 0) with these values

       */
        int m=0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = SIZE-1; j >=0; --j) {
                imageNew[i][m] =image[j][i];
                m++;

            }
            m=0;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=imageNew[i][j];
            }
        }

    }


}






void Darken_Lighten(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          if(s[0]=='D'){ // If user want Darken mode on image
              image[i][j]=image[i][j]/2.5; //To make all ratios tend to zero as much as possible

          }
          else{ // if user want Light mode on image
              image[i][j]=image[i][j]+(255-image[i][j])/2; //To increase its brightness by 50% we use this
              // equation and make sure that it will not exceed 255
              // by subtract the original value from 255 and divide it
              //after that we sum it to its original value
          }


        }
    }


}
void edge(){
    /*The first step: Convert the image to black and white by doing this. If the pixel value is greater than 127, it is set to 255 (white)
     and if the pixel value is less than 127, it is set to 0 (black).
     The second step: The outline of all pixel values is calculated by summing them and dividing them by the total number of pixels (256*256).
     The third step: Compare the current pixel value with the pixel values surrounding it. If the difference is higher than serious,
     it is saved in the new image with a value of 0 (black), and if it is not less than or equal to the average, it is saved
     in the new image with a value of 255 (white).
     The final step: transfer the new image to the original image*/

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;}}

    int ave=0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            ave+=image[i][j];
        }}
    ave=ave/(256*256);

    for (int i = 1; i < SIZE-1; i++) {
        for (int j = 1; j < SIZE-1; j++) {
            int current=image[i][j];
            int down=image[i+1][j];
            int left=image[i][j-1];
            if(::abs(current-down)>ave||::abs(current-left)>ave)
                imageNew[i][j]=0;
            else
                imageNew[i][j]=255;
        }}
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = imageNew[i][j];
        }
    }

}



void Enlarge_image(){

    /* every index in the image will be representing in 4 index in the new image
     * (the same index and the one below it, and the one on its right,
     * and the one above it, and the one on its right
*/
    int quarter; cin>>quarter;
    if(quarter==1){
        int k=0,y=1,l=0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; ++j) {
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
                k++;
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
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
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
                k++;
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
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
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
                k++;
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
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
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
                k++;
                imageNew[l][k]=image[i][j];
                imageNew[y][k]=image[i][j];
                k++;

            }
            k=0;
            l+=2;
            y+=2;

        }


    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=imageNew[i][j];
        }
    }

}








void shrank() {
    /* The user input his image and shrink this image by puting many pixels from his image
     * to one pixel from new image */

    int nn;
    cin>>nn;

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j]=255;
        }

    }

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(nn==2){
                image3[i/2][j/2]=image[i][j];
            }
            else if(nn==3){
                image3[i/3][j/3]=image[i][j];

            }
            else {
                image3[i/4][j/4]=image[i][j];
            }

        }

    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=image3[i][j];

        }

    }




}
void Mirror_image(){
    /*The user is asked to enter the direction of the half of the image that he wants to reflect on the mirror
If it is left, the pixel values from the right part of the image will be copied to. Left part
If it is the right, the pixel values will be copied from the left part to the right part
If it is the bottom, the pixel values are copied from the top to the bottom
If not, the values will be copied from the bottom part to the top part*/
    string ss;
    cin>>ss;
    if(ss=="left"){
        for (int i = 0; i < SIZE; i++) {
            for( int j = 0; j< SIZE/2; j++) {
                image[i][SIZE - 1 - j] = image[i][j];
            }}}
    else if(ss=="right"){
        for (int i = 0; i < SIZE; i++) {
            for( int j = 0; j< SIZE/2; j++) {
                image[i][j] = image[i][SIZE - 1 - j];
            }}}
    else if(ss=="lower"){
        for (int i = 0; i < SIZE/2; i++) {
            for( int j = 0; j< SIZE; j++) {
                image[i][j] = image[SIZE - 1 - i][j];
            }}}
    else{
        for (int i = 0; i < SIZE/2; i++) {
            for( int j = 0; j< SIZE; j++) {
                image[SIZE-1-i][j]=image[i][j];}
        }
    }

}

void Shuffle_Image(){

    // We have 4 probabilities: Every quarter in the new image has 4 probabilities

    int l=4,n,m=0;
    while(l--){
        cin>>n;
        if(m==0){
            //    1- The quarter 1 in the new image has 4 probabilities
            int k=0,d=0;
            //    row in the new image start with 0,column start with 0
            if(n==1){
                /*      if the user want 1 we will
                      put the quarter 1 from the image in the quarter 1 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[i][j]=image[i][j];
                    }
                }
                m++;
            }
            else if(n==2){
                /*    if the user want 2 we will
                    put the quarter 2 from the image in the quarter 1 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[i][k]=image[i][j];
                        k++;
                    }
                    k=0;
                }
                m++;
            }
            else if(n==3){
                /*    if the user want 3 we will
                put the quarter 3 from the image in the quarter 1 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[d][j]=image[i][j];
                    }
                    d++;
                }
                m++;
            }
            else if(n==4){
                /*    if the user want 4 we will
                put the quarter 4 from the image in the quarter 1 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[d][k]=image[i][j];
                        k++;
                    }
                    k=0;
                    d++;
                }
                m++;
            }
        }
            //   -----------------------------------
            //The second probability  in the quarter 2 in the new image
        else if(m==1){
            int k,d=0;
            //    row in the new image start with 0,column start with 128
            if(n==1){
                /*    if the user want 1 we will put the quarter 1
                  from the image in the quarter 2 in the new image */
                k=128;
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[i][k]=image[i][j];
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==2){
                /*    if the user want 2 we will put the quarter 2
                  from the image in the quarter 2 in the new image */
                k=128;
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[i][k]=image[i][j];
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==3){
                /*    if the user want 3 we will put the quarter 3
                  from the image in the quarter 2 in the new image */
                k=128;
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[d][k]=image[i][j];
                        k++;
                    }
                    k=128;
                    d++;
                }
                m++;
            }
            else if(n==4){
                /*    if the user want 4 we will put the quarter 4
                  from the image in the quarter 2 in the new image */
                k=128;
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[d][k]=image[i][j];
                        k++;
                    }
                    k=128;
                    d++;
                }
                m++;
            }
        }
            //------------------------------------
            //The third probability  in the quarter 3 in the new image
        else if (m==2){
            //    row in the new image start with 128,column start with 0
            int d=128,k=0;
            if(n==1){
                /*    if the user want 1 we will put the quarter 1
                  from the image in the quarter 3 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[d][j]=image[i][j];
                    }
                    d++;
                }
                m++;
            }
            else if(n==2){
                /*    if the user want 2 we will put the quarter 2
                  from the image in the quarter 3 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[d][k]=image[i][j];
                        k++;
                    }
                    k=0;
                    d++;
                }
                m++;
            }
            else if(n==3){
                /*    if the user want 3 we will put the quarter 3
                  from the image in the quarter 3 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[i][j]=image[i][j];
                    }
                }
                m++;
            }
            else if(n==4){
                /*    if the user want 4 we will put the quarter 4
                  from the image in the quarter 3 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[i][k]=image[i][j];
                        k++;
                    }
                    k=0;
                }
                m++;
            }
        }
            //-----------------------------------
            // The final probability in the quarter 4 in the new image
        else if(m==3){
            //    row in the new image start with 128,column start with 128
            int d=128,k=128;
            if(n==1){
                /*    if the user want 1 we will put the quarter 1
                  from the image in the quarter 4 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[d][k]=image[i][j];
                        k++;

                    }
                    d++;
                    k=128;

                }
                m++;
            }
            else if(n==2){
                /*    if the user want 2 we will put the quarter 2
                  from the image in the quarter 4 in the new image */
                for (int i = 0; i < 128; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[d][j]=image[i][j];
                    }
                    d++;
                }
                m++;
            }
            else if(n==3){
                /*    if the user want 3 we will put the quarter 3
                  from the image in the quarter 4 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 0; j <128 ; ++j) {
                        imageNew[i][k]=image[i][j];
                        k++;
                    }
                    k=128;
                }
                m++;
            }
            else if(n==4){
                /*    if the user want 4 we will put the quarter 4
                  from the image in the quarter 4 in the new image */
                for (int i = 128; i < SIZE; ++i) {
                    for (int j = 128; j <SIZE ; ++j) {
                        imageNew[i][j]=image[i][j];
                    }
                }
                m++;
            }
        }
    }

    if(m==4){
        for (int i = 0; i <SIZE ; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=imageNew[i][j];
            }
        }
    }

}

void crop() {
    /* In this filter user input image and the index of start in this image,
     * width and hight after that make new image that stat from this point to the widht and height he input
     */

int n=0,l=0;
    int x,y,w,m;
cout<<"Enter the point (x,y) you want to start from : ";
cin>>x>>y; cout<<endl;
cout<<"Enter the Length and width you want : ";
cin>>w>>m;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image3[i][j]=255;

        }

    }
    for (int i = x; i < m ; i++) {
        for (int j = y; j < w; j++) {
            image3[n][l]=image[i][j];
            l++;
        }
        n++;
        l=0;

    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=image3[i][j];

        }

    }



}

void plur(){
    /* In this filter we take the average of each pixel by taking all around pixel
     * and divide it on its number
     */

       for(int k=0 ; k<10 ; k++){
           for (int i = 0; i < SIZE; i++) {
               for (int j = 0; j < SIZE; j++) {
                   if(i==0&&j==0){
                       image3[i][j]=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
                   }
                   if(i==0&&j==SIZE-1){
                       image3[i][j]=(image[i][j]+image[i][j-1]+image[i+1][j]+image[i+1][j-1])/4;
                   }
                   if(i==SIZE-1&&j==0){
                       image3[i][j]=(image[i][j]+image[i-1][j]+image[i][j+1]+image[i-1][j+1])/4;
                   }
                   if(i==SIZE-1&&j==SIZE-1){
                       image3[i][j]=(image[i][j]+image[i][j-1]+image[i-1][j]+image[i-1][j-1])/4;
                   }
                   if(i>0&&j==0){
                       image3[i][j]=(image[i][j]+image[i-1][j]+image[i+1][j]+image[i][j+1]+image[i-1][j+1]+image[i+1][j+1])/6;

                   }
                   if(i==0&&j>0){
                       image3[i][j]=(image[i][j]+image[i][j+1]+image[i][j-1]+image[i+1][j]+image[i+1][j+1]+image[i+1][j-1])/6;

                   }
                   if(i==SIZE-1&&j>0){
                       image3[i][j]=(image[i][j]+image[i][j+1]+image[i][j-1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j-1])/6;

                   }
                   if(i>0&&j==SIZE-1){
                       image3[i][j]=(image[i][j]+image[i-1][j]+image[i+1][j]+image[i][j-1]+image[i-1][j-1]+image[i+1][j-1])/6;

                   }
                   if(i>0&&i<SIZE-1&&j>0&&j<SIZE-1){
                       image3[i][j]=(image[i][j]+image[i-1][j]+image[i+1][j]+image[i][j-1]+image[i][j+1]+image[i-1][j-1]+image[i-1][j+1]+image[i+1][j-1]+image[i+1][j+1])/9;
                   }

               }


           }
           for (int i = 0; i < SIZE; ++i) {
               for (int j = 0; j < SIZE; ++j) {
                   image[i][j]=image3[i][j];

               }

           }





       }






}

void skew() {

    /* we start to get the angle the user want and get the width of this image
     * after that we shrink this image to be from 0 to x(width) , after that
     * we make step to know the point of start in new array and move to know
     * how will minus the step to reach to end of image
     */
    string w;
    cin >> w;

    if (w[0] == 'v') {
        cout << "Enter an angle: ";
        float n;
        cin >> n;
        n = 90 - n;
        n = (n * 22) / (7 * 180);
        n = tan(n);
        int x = 256 / (1 + (1 / n));
        int y = x;
        x = (256 / x);


        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image3[i][j] = 255;
            }

        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < y; j++) {
                image3[i][j] = image[i][j * x];
            }
        }
        double step = 256 - y;
        double move = step / 256;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image4[i - 1][j + int(step)] = image3[i][j];
            }
            step -= move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image4[i][j];
            }

        }


    } else {
        /*The user is prompted to input the angle at which they want to skew the image ,The angle
         is re-calculated in radians, and the tangent (tan) of this angle is computed
        Two matrices,image3 and image4 are initialized with values of 255 which represent white color
        Then it shrink the image size by changing the horizontal coordinates based on the x valueand Put it in image3
        A horizontal curvature is performed on the image using the inserted angle. This is done by
        copying the downsized image image3 to image4 and changing the horizontal coordinates based on the angle value
        The final copy is stored in Image4 to the original image*/

        float angle;
        cin >> angle;
        angle = angle / 180 / 7 * 22;
        angle = tan(angle);
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image4[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image3[i][j] = 255;
            }
        }

        for (int i = 0; i < SIZE * (1 - angle); i++) {
            for (int j = 0; j < SIZE; j++) {
                image3[i][j] = image[int(i / (1 - angle))][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image4[i + int(angle * (256 - j))][j] = image3[i][j];
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image4[i][j];
            }
        }

    }

}







