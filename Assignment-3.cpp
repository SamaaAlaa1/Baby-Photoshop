#include <iostream>
#include"Image_Class.h"
#include<string>
#include<fstream>
using namespace std;
void filters_menu(){
    cout<<"1- Grayscale conversion\n2- Black and white\n3- Invert image\n4- Flip image\n5- Rotate image\n6- Exit\n";
}
void save_menu3(){
    cout<<"1- Apply the filter on the current image\n2- store a new image\n3- Exit without save\n";
}
void save_image2(){
    cout<<"1- store a new image\n3- Exit without save\n";
}
bool is_valid(const string&image_name){
    ifstream file(image_name);
    return file.good();
}
Image grayscale(string image_name ){
    Image image(image_name);
    for( int i=0; i< image.width; i++){
        for(int j=0; j< image.height; j++){
            unsigned int avg = 0;
            for(int k=0; k < 3; k++) {
                if(image(i, j, k) >= 255){
                    image(i, j, k) = 255;
                }
                if(image(i, j, k) <= 0){
                    image(i, j, k) = 0;
                }
                avg += image(i, j, k );

            }
            avg /= 3;
            for(int k=0; k < 3; k++) {
                image(i, j, k ) = avg;

            }
        }
    }while(true) {
        int save_choice;
        save_menu3();
        cin>>save_choice;
        if(save_choice == 1){
            image.saveImage(image_name);
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 2){
            string filename;
            cout<<"Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
            cin>>filename;
            string extention = filename.substr((filename.length()-4), filename.length());
            if(extention != ".jpg"&&extention != ".bmp"&&extention != ".png"&&extention != ".tga"){
                cout<<"the extention is not true...\a"<<endl;
                continue;
            }
            image.saveImage(filename) ;
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 3){
            cout<<"\aExiting the program..........\n";
            break;
        }else{
            cout<<"\aInvalid input try again:\n";
        }
    }
    return image;
}
void black_white(string image_name){
    Image image(image_name);
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            int avg = 0;
            for(int k =0; k < image.channels; k++){
                avg += image(i,j,k);
            }
            avg /= 3;
            for(int k =0; k < image.channels; k++){
                image(i,j,k) = avg;
            }
        }
    }
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            for(int k =0; k < image.channels; k++){
                if(image(i,j,k)  >= 127.5){
                    image(i,j,k) = 255;
                }
                else{
                    image(i,j,k) = 0;
                }
            }
        }
    }while(true) {
        int save_choice;
        save_menu3();
        cin>>save_choice;
        if(save_choice == 1){
            image.saveImage(image_name);
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 2){
            string filename;
            cout<<"Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
            cin>>filename;
            string extention = filename.substr((filename.length()-4), filename.length());
            if(extention != ".jpg"&&extention != ".bmp"&&extention != ".png"&&extention != ".tga"){
                cout<<"the extention is not true...\a"<<endl;
                continue;
            }
            image.saveImage(filename) ;
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 3){
            cout<<"\aExiting the program..........\n";
            break;
        }else{
            cout<<"\aInvalid input try again:\n";
        }
    }
}
void flip_image(string image_name){
    while (true){
        Image image(image_name);
        cout << "1- Flip Horizontally\n2- Flip Vertical\n3- Exit\nchoose: ";
        char choice;
        cin >> choice;
        if(choice == '1'){
            for(int i = 0; i < image.width/2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        int temp = image(i,j,k);
                        image(i,j,k) = image(image.width-i,j,k);
                        image(image.width-i,j,k) = temp;

                    }
                }
            }
            while(true) {
                int save_choice;
                save_menu3();
                cin>>save_choice;
                if(save_choice == 1){
                    image.saveImage(image_name);
                    cout<<"....the image is saved successfully...."<<endl;
                    break;
                }else if(save_choice == 2){
                    string filename;
                    cout<<"Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
                    cin>>filename;
                    string extention = filename.substr((filename.length()-4), filename.length());
                    if(extention != ".jpg"&&extention != ".bmp"&&extention != ".png"&&extention != ".tga"){
                        cout<<"the extention is not true...\a"<<endl;
                        continue;
                    }
                    image.saveImage(filename) ;
                    cout<<"....the image is saved successfully...."<<endl;
                    break;
                }else if(save_choice == 3){
                    cout<<"\aExiting the program..........\n";
                    break;
                }else{
                    cout<<"\aInvalid input try again:\n";
                }
            }
        }
        else if(choice == '2'){
            for(int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height/2; j++) {
                    for (int k = 0; k < image.channels; k++) {
                        int temp = image(i,j,k);
                        image(i,j,k) = image(i,image.height-j,k);
                        image(i,image.height-j,k) = temp;

                    }
                }
            }
            while(true) {
                int save_choice;
                save_menu3();
                cin>>save_choice;
                if(save_choice == 1){
                    image.saveImage(image_name);
                    cout<<"....the image is saved successfully...."<<endl;
                    break;
                }else if(save_choice == 2){
                    string filename;
                    cout<<"Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
                    cin>>filename;
                    string extention = filename.substr((filename.length()-4), filename.length());
                    if(extention != ".jpg"&&extention != ".bmp"&&extention != ".png"&&extention != ".tga"){
                        cout<<"the extention is not true...\a"<<endl;
                        continue;
                    }
                    image.saveImage(filename) ;
                    cout<<"....the image is saved successfully...."<<endl;
                    break;
                }else if(save_choice == 3){
                    cout<<"\aExiting the program..........\n";
                    break;
                }else{
                    cout<<"\aInvalid input try again:\n";
                }
            }
        }
        else if(choice == '3'){
            break;
        }
        else{
            cout << "\nPlease choose a valid choice\n";
            continue;
        }
    }
}
void image_inverter(string image_name){

    Image picture(image_name);

    for (int i = 0; i < picture.width; i++) {

        for (int j = 0; j < picture.height; j++) {

            for (int k = 0; k < picture.channels; k++) {
                // Get the original pixel value

                int pixel_value = picture.getPixel(i, j, k);


                // Invert the color channel

                pixel_value = 255 - pixel_value;

                // Set the inverted pixel value

                picture.setPixel(i, j, k, pixel_value);
            }
        }
    }
    while(true) {
        int save_choice;
        save_menu3();
        cin>>save_choice;
        if(save_choice == 1){
            picture.saveImage(image_name);
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 2){
            string filename;
            cout<<"Enter the name of the new image with extension:\n(.jpg , .bmp, .png, .tga\n";
            cin>>filename;
            string extention = filename.substr((filename.length()-4), filename.length());
            if(extention != ".jpg"&&extention != ".bmp"&&extention != ".png"&&extention != ".tga"){
                cout<<"the extention is not true...\a"<<endl;
                continue;
            }
            picture.saveImage(filename) ;
            cout<<"....the image is saved successfully...."<<endl;
            break;
        }else if(save_choice == 3){
            cout<<"\aExiting the program..........\n";
            break;
        }else{
            cout<<"\aInvalid input try again:\n";
        }
    }
}
void rotation ( string image_name){

    Image original_image(image_name);//variable of data type image

// this filter can rotate the entered image by angle 90 or 180 or 270 so make the user choose his desire
    int angle ;

    cout << "Enter rotation angle (180,90 or 270): "<<endl;

    cin>> angle ;

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

        while (true) {
            int save_choice;
            save_menu3();
            cin >> save_choice;
            if (save_choice == 1) {
                rotated_image.saveImage(image_name);
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
                rotated_image.saveImage(filename);
                cout << "....the image is saved successfully...." << endl;
                break;
            } else if (save_choice == 3) {
                cout << "\aExiting the program..........\n";
                break;
            } else {
                cout << "\aInvalid input try again:\n";
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
        while (true) {
            int save_choice;
            save_menu3();
            cin >> save_choice;
            if (save_choice == 1) {
                rotated_image.saveImage(image_name);
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
                rotated_image.saveImage(filename);
                cout << "....the image is saved successfully...." << endl;
                break;
            } else if (save_choice == 3) {
                cout << "\aExiting the program..........\n";
                break;
            } else {
                cout << "\aInvalid input try again:\n";
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
        while (true) {
            int save_choice;
            save_menu3();
            cin >> save_choice;
            if (save_choice == 1) {
                rotated_image.saveImage(image_name);
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
                rotated_image.saveImage(filename);
                cout << "....the image is saved successfully...." << endl;
                break;
            } else if (save_choice == 3) {
                cout << "\aExiting the program..........\n";
                break;
            } else {
                cout << "\aInvalid input try again:\n";
            }

        }
    }
    else {
        cout <<"invalid input "<<endl;
    }

}
int main(){
    string image_name;
    while(true) {
        cout << "Enter the name of the image you want to apply the filter on:\n";
        cin >> image_name;
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
    }while(true) {
        int filter_choice;
        filters_menu();
        cin >> filter_choice;
        if(filter_choice == 1){
            grayscale(image_name);
        }else if(filter_choice == 2){
            black_white(image_name);
        }else if(filter_choice == 3){
            image_inverter(image_name);
        }else if(filter_choice == 4){
            flip_image(image_name);
        }else if(filter_choice == 5){
            rotation(image_name);
        }else if(filter_choice == 6){
            cout<<"\aExiting the program..........\n";
            break;
        }else {
            cout<<"\aInvalid input please try again:\n";
        }
    }
}