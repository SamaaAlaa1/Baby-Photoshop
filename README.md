# Assignment-3
#include <iostream>
#include"Image_Class.h"
#include<string>
#include<fstream>
using namespace std;
bool is_valid(const string&image_name){
    ifstream file(image_name);
    return file.good();
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
                Image image(image_name);
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
}
int main(){
    string image_name;
    while(true) {

        cout << "Enter the name of the image you want to apply the filter on:\n";
        cin >> image_name;
        Image image(image_name);
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
        }else if(filter_choice == 5){
            flip_image(image_name, image);
            saveandload_again(image_name, image);
        }else if(filter_choice == 6) {
            rotation(image_name, image);
            saveandload_again(image_name, image);
        
        }else if(filter_choice == 16){
            cout<<"\aExiting the program..........\n";
            break;
        }else {
            cout<<"\aInvalid input please try again:\n";
        }
    }

    return 0;
}
