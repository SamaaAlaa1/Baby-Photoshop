/*
 Author : Bassant Salem Tohami   _ID : 20231035 _s11
        : grayscale_merge images_Darken and lighten images_detect edges_sunlight_main
Author : Samaa Alaa Abdelmaqsoud  _ID : 20231035 _s11
        :black and white_flip image_Crop Images_Resizing Images_purple
Author : Marwa Sayed Sallam  ID : 20231158 _s11
        :Invert Image_Rotate Image_ِAdding a Frame to the Picture_Blur Images_oil painting
link of our repo on github :
            https://github.com/SamaaAlaa1/Assignment-3.git
link of the diagram :
        https://drive.google.com/file/d/1XqwfDdx95vggXi2vvnk9bGtNcsAdSMbi/view?usp=sharing

  */
#include <iostream>
#include"Image_Class.h"
#include<string>
#include<fstream>
using namespace std;
void lighten_and_darken(string& image_name, Image& image){
    cout<<"Enter your choice.......\n1-Make the image lighter\n2-Make the image darker"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1){
       for(int i=0; i<image.width; i++){
            for(int j=0; j<image.height; j++){
                for(int k=0; k<3; k++){

                    round(image(i,j,k) += 14.33);
                    if(image(i,j,k) > 255){
                        image(i,j,k) = 255;
                    }if(image(i,j,k) < 0){
                        image(i,j,k) = 0;
                    }
                }
            }
        }
    }if(choice == 2){
        for(int i=0; i<image.width; i++){
            for(int j=0; j<image.height; j++){
                for(int k=0; k<3; k++){
                    if(image(i,j,k) > 255){
                        image(i,j,k) = 255;
                    }if(image(i,j,k) < 0){
                        image(i,j,k) = 0;
                    }
                    trunc(image(i,j,k) *= 0.33);
                    if(image(i,j,k) < 0){
                        image(i,j,k) = 0;
                    }
                }
            }
        }
    }
}
void merge(string name1){
    Image image1(name1);
    string name2;
    while(true){
        cout<<"Enter the second image name to apply merge:\n";
        cin>>name2;
        Image image2(name2);
        if(!is_valid(name2)){
            cout<<"\aThe image is not found please try again:\n";
        }else{
            try {
                Image image2(name2);
                cout<<"-----------The image is loaded successfully---------\n";
                break;
            }catch(exception) {
                cout<<"Invalid input please try again...\a\n";
            }
        }
    }Image image2(name2);
    cout<<"Enter your choice to apply merge on..........\n1- Resize one of two images\n2- Apply on the common area\n";
    int merge_choice;
    cin>>merge_choice;
    if(merge_choice == 1){
        cout<<"Enter your choice ......\n1- Resize to the bigger one\n2- Resize to the smaller one\n";
        int resize_choice;
        cin>>resize_choice;
        if(resize_choice == 1){
            int maxwidth = max(image1.width, image2.width);
            int maxheight = max(image1.height, image2.height);
            Image image(maxwidth, maxheight);

            if(maxwidth == image2.width && maxheight == image2.height){
                float newwidth = float(image1.width) / maxwidth;
                float newheight =float( image1.height) / maxheight;
                Image resized(maxwidth, maxheight);
                for(float i=0; i<maxwidth; i++){
                    for(float j=0; j<maxheight; j++){
                        int w = round(i*newwidth);
                        int h = round(j*newheight);
                        for(int k=0; k<3 ; k++){
                            resized(i, j, k) = image1(w, h, k);
                        }
                    }
                }for(int i=0; i<maxwidth; i++){
                    for(int j=0; j<maxheight; j++){
                        for(int k=0; k<3; k++){
                            image(i, j, k) = (image2(i, j, k) + resized(i, j, k))/2;
                        }
                    }
                }


            }if(image1.width == maxwidth && image1.height == maxheight){
                float newwidth = float(image2.width) / maxwidth;
                float newheight = float(image2.height) / maxheight;
                Image resized(maxwidth, maxheight);
                for(float i=0; i<maxwidth; i++){
                    for(float j=0; j<maxheight; j++){
                        int w = round(i*newwidth);
                        int h = round(j*newheight);
                        for(int k=0; k<3 ; k++){
                            resized(i, j, k) = image2(w, h, k);
                        }
                    }
                }for(int i=0; i<maxwidth; i++){
                    for(int j=0; j<maxheight; j++){
                        for(int k=0; k<3; k++){
                            image(i, j, k) = (image1(i, j, k) + resized(i, j, k))/2;
                        }
                    }
                }


            }
        }else if(resize_choice == 2){
            int minwidth = min(image1.width, image2.width);
            int minheight = min(image1.height, image2.height);
            Image image(minwidth, minheight);

            if(minwidth == image2.width && minheight == image2.height){
                float newwidth = float(image1.width) / minwidth;
                float newheight =float( image1.height) / minheight;
                Image resized(minwidth, minheight);
                for(float i=0; i<minwidth; i++){
                    for(float j=0; j<minheight; j++){
                        int w = round(i*newwidth);
                        int h = round(j*newheight);
                        for(int k=0; k<3 ; k++){
                            resized(i, j, k) = image1(w, h, k);
                        }
                    }
                }for(int i=0; i<minwidth; i++){
                    for(int j=0; j<minheight; j++){
                        for(int k=0; k<3; k++){
                            image(i, j, k) = (image2(i, j, k) + resized(i, j, k))/2;
                        }
                    }
                }

            }if(image1.width == minwidth && image1.height == minheight){
                float newwidth = float(image2.width) / minwidth;
                float newheight = float(image2.height) / minheight;
                Image resized(minwidth, minheight);
                for(float i=0; i<minwidth; i++){
                    for(float j=0; j<minheight; j++){
                        int w = round(i*newwidth);
                        int h = round(j*newheight);
                        for(int k=0; k<3 ; k++){
                            resized(i, j, k) = image2(w, h, k);
                        }
                    }
                }for(int i=0; i<minwidth; i++){
                    for(int j=0; j<minheight; j++){
                        for(int k=0; k<3; k++){
                            image(i, j, k) = (image1(i, j, k) + resized(i, j, k))/2;
                        }
                    }
                }


            }
        }else{
            cout<<"Invalid input please try again\a\n";
        }
    }
    else if(merge_choice == 2) {
        int commomnwidth = min(image1.width, image2.width);
        int commonheight = min(image1.height, image2.height);
        Image image(commomnwidth, commonheight);
        for (int i = 0; i < commomnwidth; i++) {
            for (int j = 0; j < commonheight; j++) {
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
                }
            }
        }
        while (true){
            cout<<"Enter your choice.......\n1- store a new image\n2- exciting without save\n";
            int save_choice;
            cin>>save_choice;
            if(save_choice == 1){
                string filename;
                cout<<"Enter the new image name  with extension:\n(.jpg , .bmp, .png, .tga\n";
                cin>>filename;
                image.saveImage(filename);
                cout << "....the image is saved successfully...." << endl;
                break;
            }else if (save_choice == 2){
                cout<<"Exciting the program...............\n";
                break;
            }else{
                cout<<"\aInvalid input please try again\n";
            }
        }

    }else{
        cout<<"Invalid choice try again....\a\n";
    }
}
void sunlight(string& image_name, Image& image){
    for(int i=0; i<image.width; i++){
        for(int j=0; j<image.height; j++){
            image(i, j, 2) *= 0.5;
        }
    }for(int i=0; i<image.width; i++){
        for(int j=0; j<image.height;j++){
            for(int k=0; k<3; k++){
                if(image(i,j,k) > 255 ) image(i, j, k) = 255;
                if(image(i,j,k) < 0 ) image(i, j, k) = 0;
            }
        }
    }
}
bool is_valid(const string&image_name){
    ifstream file(image_name);
    return file.good();
}
void cropped(string& image_name , Image& image){
    int x,y,width,height;
    while (true){
        cout << "Enter the dimensions to crop to: \nx: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        cout << "Width: ";
        cin >> width;
        cout << "Height: ";
        cin >> height;
        if(x < 0 || y < 0 || width <= 0 || height <= 0 || x + width > image.width || y + height > image.height) {
            cout << "Error: Invalid cropping dimensions." << endl;
            continue;
        }
        else break;
    }
    Image cropped(width,height);
    for(int i=0;i<width;i++){
        for(int j = 0;j < height; j++){
            for(int k = 0;k < image.channels; k++){
                cropped(i,j,k) = image(x+i,y+j,k);
            }
        }
    }
    image = cropped;
}
void purble(string& image_name, Image& image){
    for(int i = 0;i < image.width; i++){
        for(int j = 0;j < image.height; j++){
                image(i,j,1) -= (image(i,j,1)*1/2 );
        }
    }
}
void resize(string& image_name, Image& image){
    float height,width;
    cout << "Enter a new dimensions:\n width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    Image resized(width,height);
    float r = float(image.width) / width;
    float c = float(image.height) / height;
    for(float i = 0 ;i < width;i++){
        for(float j = 0;j < height;j++){
             int w = round(i*r);
             int h = round(j*c);
            for(int k = 0;k<image.channels;k++){
                resized(i, j,k) =  image(w,h,k);
            }
        }
    }
    image = resized;
}
void grayscale(string& image_name, Image& image ) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++) {
                if (image(i, j, k) >= 255) {
                    image(i, j, k) = 255;
                }
                if (image(i, j, k) <= 0) {
                    image(i, j, k) = 0;
                }
                avg += image(i, j, k);

            }
            avg /= 3;
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = avg;

            }
        }
    }
}

void black_white(string& image_name, Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = avg;
            }
        }
    }
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                if (image(i, j, k) >= 127.5) {
                    image(i, j, k) = 255;
                } else {
                    image(i, j, k) = 0;
                }
            }
        }
    }
}
void flip_image(string& image_name, Image& image) {
    while (true) {
        cout << "1- Flip Horizontally\n2- Flip Vertical\n3- Exit\nchoose: ";
        char choice;
        cin >> choice;
        if (choice == '1') {
            for (int i = 0; i < image.width / 2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        int temp = image(i, j, k);
                        image(i, j, k) = image(image.width - i, j, k);
                        image(image.width - i, j, k) = temp;

                    }
                }
            }
        } else if (choice == '2') {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height / 2; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        int temp = image(i, j, k);
                        image(i, j, k) = image(i, image.height - j, k);
                        image(i, image.height - j, k) = temp;

                    }
                }
            }
        }
    }
}
void image_inverter(string& image_name, Image& image ) {

    for (int i = 0; i < image.width; i++) {

        for (int j = 0; j < image.height; j++) {

            for (int k = 0; k < image.channels; k++) {
                // Get the original pixel value

                int pixel_value = image.getPixel(i, j, k);


                // Invert the color channel

                pixel_value = 255 - pixel_value;

                // Set the inverted pixel value

                image.setPixel(i, j, k, pixel_value);
            }
        }
    }
}
void rotation ( string& image_name, Image& image) {

    Image original_image(image_name);//variable of data type image

// this filter can rotate the entered image by angle 90 or 180 or 270 so make the user choose his desire
    int angle;

    cout << "Enter rotation angle (180,90 or 270): " << endl;

    cin >> angle;

    if (angle == 180) {

        Image rotated_image(original_image.width, original_image.height);

        for (int i = 0; i < original_image.width; i++) {

            for (int j = 0; j < original_image.height; j++) {

                for (int k = 0; k < original_image.channels; k++) {

                    rotated_image(original_image.width - 1 - i, original_image.height - 1 - j, k) = original_image(i, j,
                                                                                                                   k);
                }
            }
        }
    }
    else if (angle == 90) {

        Image rotated_image(original_image.height, original_image.width);

        for (int i = 0; i < original_image.width; i++) {

            for (int j = 0; j < original_image.height; j++) {

                for (int k = 0; k < original_image.channels; k++) {

                    rotated_image(j, original_image.width - 1 - i, k) = original_image(i, j, k);

                }
            }
        }
    }
    else if (angle == 270) {

        Image rotated_image(original_image.height, original_image.width);

        for (int i = 0; i < original_image.width; i++) {
            for (int j = 0; j < original_image.height; j++) {
                for (int k = 0; k < original_image.channels; k++) {
                    rotated_image(original_image.height - 1 - j, i, k) = original_image(i, j, k);
                }
            }
        }
    }
}
void saveandload_again(string&image_name, Image&image){
    cout<<"Enter your choice\n1- load a new image\n2- Save image\n3- continue applying filters\n";
    int user_choice;
    while (true) {
        cin >> user_choice;
        if (user_choice == 1) {
            string image_name;
            while (true) {
                cout << "Enter the name of the image you want to apply the filter on:\n";
                cin >> image_name;
                if (!is_valid(image_name)) {
                    cout << "\aThe image is not found please try again....\n";
                } else {
                    try {

                        Image image(image_name);
                        cout << "------------image loaded successfully----------\n";
                        break;
                    }
                    catch (exception) {
                        cout << "\aincorrect input please try again....\n";
                    }
                }
            }
        }
        else if (user_choice == 2) {
            while (true) {
                cout << "1- Apply the filter on the current image\n2- store a new image\n3- Exit without save\n";
                int save_choice;
                cin >> save_choice;
                if (save_choice == 1) {
                    image.saveImage(image_name);
                    cout << "....the image is saved successfully...." << endl;
                    break;
                } else if (save_choice == 2) {
                    string filename;
                    cout << "Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
                    cin >> filename;
                    string extention = filename.substr((filename.length() - 4), filename.length());
                    if (extention != ".jpg" && extention != ".bmp" && extention != ".png" && extention != ".tga") {
                        cout << "the extention is not true...\a" << endl;
                        continue;
                    }
                    image.saveImage(filename);
                    cout << "....the image is saved successfully...." << endl;
                    break;
                } else if (save_choice == 3) {
                    cout << "\aExiting the program..........\n";
                    break;
                }
                else {
                    cout << "\aInvalid input try again:\n";
                }
            }
            break;
        }else if(user_choice == 3){
            break;
        }
        else{
            cout<<"\aInvalid input please try again\n";
        }
    }
}int main(){
    string image_name;
    while(true) {

        cout << "Enter the name of the image you want to apply the filter on:\n";
        while(true) {
            cin >> image_name;

            string extention = image_name.substr((image_name.length() - 4), image_name.length());
            if (extention != ".jpg" && extention != ".bmp" && extention != ".png" && extention != ".tga") {
                cout << "the extention is not true...\a" << endl;
                continue;
            }else{
                break;
            }
        }Image image (image_name);
        if(!is_valid(image_name)){
            cout << "\aThe image is not found please try again....\n";
        }else {
            try {

                Image image(image_name);
                cout << "------------image loaded successfully----------\n";
                break;
            }
            catch (exception) {
                cout << "\aincorrect input please try again....\n";
            }
        }
    }
while(true) {
        Image image(image_name);
        int filter_choice;
        cout<<"1- Grayscale conversion\n2- Black and white\n3- Invert image\n4- Merge images\n5- Flip image\n6- Rotate image\n7- Darken and lighten image\n8- Crop image\n9- Adding frame to the picture\n10- Detect Image Edges\n11- Resizing Images\n12- Blur Images\n13- natural sunlight\n14- Oil painting\n15- purple\n16- Exit\nEnter your choice\n";
        cin >> filter_choice;
        if(filter_choice == 1){
            grayscale(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 2){
            black_white(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 3){
            image_inverter(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 4){
            merge(image_name);
           
        }
        else if(filter_choice == 5){
            flip_image(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 6) {
            rotation(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 7){
            lighten_and_darken(image_name, image);
            saveandload_again(image_name, image);
        }
        else if(filter_choice == 8){
            cropped(image_name, image);
            saveandload_again(image_name, image);
        }
        else if(filter_choice == 11){
            resize(image_name, image);
            saveandload_again(image_name, image);

        }else if(filter_choice == 13){
            sunlight(image_name, image);
            saveandload_again(image_name, image);
        }
        else if(filter_choice == 15){
            purble(image_name, image);
            saveandload_again(image_name, image);
        }
        else if(filter_choice == 16){
            cout<<"\aExiting the program..........\n";
            break;
        }else {
            cout<<"\aInvalid input please try again:\n";
        }
    }
    return 0;
}
