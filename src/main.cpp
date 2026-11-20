#include <sil/sil.hpp>
#include "random.hpp"
#include <algorithm>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <complex>


void exo1_vert(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}

void exo2_echange_canaux(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
}

void exo3_noir_et_blanc(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3(((color.r + color.g + color.b) / 3.f));
    }
}

void exo4_negatif(sil::Image& image){
    for (glm::vec3& color : image.pixels())
    {
        color.r = 1-color.r;
        color.g = 1-color.g;
        color.b = 1-color.b;
    }
}

void exo5_degrade(sil::Image& image2){
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x,y).r = x/299.f;
            image2.pixel(x,y).g = x/299.f;
            image2.pixel(x,y).b = x/299.f;
        }
    }
}

void exo6_miroir(sil::Image& image){
    sil::Image copie = image;
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            copie.pixel(x, y)= image.pixel(image.width()-1-x, y);
        }
    }
    image = copie;
}

void exo7_image_bruitee(sil::Image& image){
    int nb = random_int(10000, 50000);
    for (int i = 0; i<nb; i++){
        int x = random_int(0, image.width());
        int y = random_int(0, image.height());
        float color_r = random_float(0.f, 1.f);
        float color_g = random_float(0.f, 1.f);
        float color_b = random_float(0.f, 1.f);
        image.pixel(x, y).r = color_r;
        image.pixel(x, y).g = color_g;
        image.pixel(x, y).b = color_b;
    }
}

void exo8_rotation(sil::Image& image){
    sil::Image copie{image.height(), image.width()};
    for (int x{0}; x < copie.width(); x++)
    {
        for (int y{0}; y < copie.height(); y++)
        {
            copie.pixel(x, y)= image.pixel(y, image.height()-1-x);
        }
    }
    image = copie;
}

void exo9_split(sil::Image& image){
    sil::Image copie = image;
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x>30 & x<image.width()-30){
                copie.pixel(x, y).r= image.pixel(x-30,y).r;
                copie.pixel(x, y).g= image.pixel(x,y).g;
                copie.pixel(x, y).b= image.pixel(x+30,y).b;
            
            }
            else if(x<30){
                copie.pixel(x, y).r= 0.f;
                copie.pixel(x, y).g= image.pixel(x,y).g;
                copie.pixel(x, y).b= image.pixel(x+30,y).b;
            }
            else {
                copie.pixel(x, y).r= image.pixel(x-30,y).r;
                copie.pixel(x, y).g= image.pixel(x,y).g;
                copie.pixel(x, y).b= 0.f;
            }
        }
    }
    image = copie;
}

void exo10_eclaircissement(sil::Image& image3){
    for (glm::vec3& color : image3.pixels())
    {
        color.r = color.r + 0.5;
        color.g = color.g + 0.5;
        color.b = color.b + 0.5;
        if (color.r > 1){
            color.r = 1;}
        if (color.g > 1){
            color.g = 1;}
        if (color.b > 1){
            color.b = 1;}
    } 
}

void exo10_assombrissement(sil::Image& image3){
    for (glm::vec3& color : image3.pixels())
    {
        color.r = color.r - 0.5;
        color.g = color.g - 0.5;
        color.b = color.b - 0.5;
        if (color.r > 1){
            color.r = 1;}
        if (color.g > 1){
            color.g = 1;}
        if (color.b > 1){
            color.b = 1;}
    } 
}

void exo11_disque(sil::Image& image2){
    int center_x = image2.width() / 2;
    int center_y = image2.height() / 2;
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            float distance = std::sqrt(std::pow(x - center_x, 2) + std::pow(y - center_y, 2));
            if(distance < 100){
                image2.pixel(x,y).r = 1.f;
                image2.pixel(x,y).g = 1.f;
                image2.pixel(x,y).b = 1.f;
            }
        }
    }
}

void exo12_cercle(sil::Image& image2){
    int center_x = image2.width() / 2;
    int center_y = image2.height() / 2;
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            float distance = std::sqrt(std::pow(x - center_x, 2) + std::pow(y - center_y, 2));
            if(distance < 101 & distance > 95){
                image2.pixel(x,y).r = 1.f;
                image2.pixel(x,y).g = 1.f;
                image2.pixel(x,y).b = 1.f;
            }
        }
    }
}

void exo13_animation(sil::Image& image2, int center_x)
{
    int center_y = image2.height() / 2;
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            float distance = std::sqrt(std::pow(x - center_x, 2) + std::pow(y - center_y, 2));
            if(distance < 100){
                image2.pixel(x,y).r = 1.f;
                image2.pixel(x,y).g = 1.f;
                image2.pixel(x,y).b = 1.f;
            }
        }
    }
}

void exo14_rosace(sil::Image& image2)
{
    exo12_cercle (image2);
    int nb_ronds = 6;
    for (int i = 0; i < nb_ronds; i++){
        float x1 = image2.width() / 2 + 100 * std::cos(i * 2 * M_PI / nb_ronds);
        float y1 = image2.height() / 2 + 100 * std::sin(i * 2 * M_PI / nb_ronds);
        for (int x{0}; x < image2.width(); x++)
        {
            for (int y{0}; y < image2.height(); y++)
            {
                float distance = std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2));
                if(distance < 101 & distance > 95){
                    image2.pixel(x,y).r = 1.f;
                    image2.pixel(x,y).g = 1.f;
                    image2.pixel(x,y).b = 1.f;
                }
            }
        }
    }
}


void exo15_mosaique(sil::Image& image){
    sil::Image copie = {image.width()*5, image.height()*5};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 5; j++){
                    copie.pixel(x+i*image.width(), y+j*image.height()) = image.pixel(x,y);
                }
            }
        }
    }
    image = copie;    
}

void exo16_mosaique_mirroir(sil::Image& image)
{
    sil::Image copie = {image.width()*5, image.height()*5};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i%2 == 0 & j%2 == 0)
            {
                for (int x{0}; x < image.width(); x++)
                {
                    for (int y{0}; y < image.height(); y++)
                    {
                        copie.pixel(i*image.width()+x, j*image.height()+y)= image.pixel(x,y);
                    }
                }
            }
            if (i%2 == 0 & j%2 == 1)
            {
                for (int x{0}; x < image.width(); x++)
                {
                    for (int y{0}; y < image.height(); y++)
                    {
                        copie.pixel(i*image.width()+x,(1+j)*image.height()-1-y)= image.pixel(x,y);
                    }
                }
            }
            if (i%2 == 1 & j%2 == 0)
            {
                for (int x{0}; x < image.width(); x++)
                {
                    for (int y{0}; y < image.height(); y++)
                    {
                        copie.pixel((1+i)*image.width()-1-x, j*image.height()+y)= image.pixel(x,y);
                    }
                }
            }
            if (i%2 == 1 & j%2 == 1)
            {
                for (int x{0}; x < image.width(); x++)
                {
                    for (int y{0}; y < image.height(); y++)
                    {
                        copie.pixel((1+i)*image.width()-1-x, (1+j)*image.height()-1-y)= image.pixel(x,y);
                    }
                }
            }
        }
    }    
    image = copie;    
}



void exo17_glitch(sil::Image& image)
{
    sil::Image copie = image;
    int nb = random_int(30, 100);
    for (int i = 0; i<nb; i++){
        int x1 = random_int(0, image.width());
        int y1 = random_int(0, image.height());
        int x2 = random_int(0, image.width());
        int y2 = random_int(0, image.height());
        int longueur = random_int(4, 35);
        int hauteur = random_int(3, 10);
        for (int j = 0; j < longueur; j++){
            for (int k = 0; k < hauteur; k++){
                if (x1+j < image.width() & y1+k < image.height() & x2+j < image.width() & y2+k < image.height()){
                    copie.pixel(x1+j, y1+k).r = image.pixel(x2+j, y2+k).r;
                    copie.pixel(x1+j, y1+k).g = image.pixel(x2+j, y2+k).g;
                    copie.pixel(x1+j, y1+k).b = image.pixel(x2+j, y2+k).b;
                    copie.pixel(x2+j, y2+k).r = image.pixel(x1+j, y1+k).r;
                    copie.pixel(x2+j, y2+k).g = image.pixel(x1+j, y1+k).g;
                    copie.pixel(x2+j, y2+k).b = image.pixel(x1+j, y1+k).b;
                }
            }
        }
    }
    image = copie;
}

float brightness(glm::vec3 const& color)
{
    return color.r + color.g + color.b;
}

void exo18_tout_trier(sil::Image& image)
{
    sil::Image copie = image;
    std::vector<glm::vec3> v{image.pixels().begin(), image.pixels().end()};
    std::sort(v.begin(), v.end(), [](glm::vec3 const& color1, glm::vec3 const& color2)
    {
        return brightness(color1) < brightness(color2); // Trie selon la luminosité des couleurs (NB : c'est à vous de coder la fonction `brightness`)
    });
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            copie.pixel(x, y) = v[x + y * image.width()]; 
        }
    }
    image = copie;
}


void exo18_trier_les_lignes(sil::Image& image)
{
    sil::Image copie = image;
    for (int y{0}; y < image.height(); y++)
    {
        std::vector<glm::vec3> v;
        for (int x{0}; x<image.width();x++)
        {
            v.push_back (image.pixel(x,y));
        }
        std::sort(v.begin(), v.end(), [](glm::vec3 const& color1, glm::vec3 const& color2)
        {
            return brightness(color1) < brightness(color2); // Trie selon la luminosité des couleurs (NB : c'est à vous de coder la fonction `brightness`)
        });
        for (int x{0}; x < image.width(); x++)
        {
            copie.pixel(x, y) = v[x]; 
        }
    }
    image = copie;
}

//void exo18


void exo19(sil::Image& image2)
{
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height();y++)
        {
            float re = x / (image2.width() - 1.f) * 4.f - 2.f;
            float im = y / (image2.height() - 1.f) * 4.f - 2.f;
            std::complex<float> c{re, im};
            std::complex<float> z{0.f, 0.f};
            
            int i = 0;
            while (i < 100 && std::abs(z) <= 2.f)
            {
                z = z * z + c;
                i++;
            }

            if (i<1)
            {
                image2.pixel(x, y).r = 0.f;
                image2.pixel(x, y).g = 0.f;
                image2.pixel(x, y).b = 0.f;
            }
            if (i>3)
            {
                image2.pixel(x, y).r = 0.12;
                image2.pixel(x, y).g = 0.12;
                image2.pixel(x, y).b = 0.12;
            }
            if (i>5)
            {
                image2.pixel(x, y).r = 0.2;
                image2.pixel(x, y).g = 0.2;
                image2.pixel(x, y).b = 0.2;
            }
            if (i>7)
            {
                image2.pixel(x, y).r = 0.4;
                image2.pixel(x, y).g = 0.4;
                image2.pixel(x, y).b = 0.4;
            }
            if (i>11)
            {
                image2.pixel(x, y).r = 0.5;
                image2.pixel(x, y).g = 0.5;
                image2.pixel(x, y).b = 0.5;
            }
            if (i>15)
            {
                image2.pixel(x, y).r = 0.6;
                image2.pixel(x, y).g = 0.6;
                image2.pixel(x, y).b = 0.6;
            }
            if (i>50)
            {
                image2.pixel(x, y).r = 1.f;
                image2.pixel(x, y).g = 1.f;
                image2.pixel(x, y).b = 1.f;
            }
        }
    }
}



void exo20_degrade_couleur(sil::Image& image2){ // pour une image de largeur 500
    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x,y).r = 1 - x/499.f;
            image2.pixel(x,y).g = x/499.f;
        }
    }
}

//void exo21(sil::Image& image3)

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation , float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void exo23_vortex(sil::Image& image){
    sil::Image copie = image;
    int center_x = image.width() / 2;
    int center_y = image.height() / 2;
    glm::vec2 center_of_rotation{center_x,center_y};
    for (int x{0}; x<image.width();x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 point{x,y};
            float angle = 0.09f * glm::distance (center_of_rotation, point);

            glm::vec2 nouveau_point = rotated(point, center_of_rotation, angle);

            if (nouveau_point[0] >= 0 && nouveau_point[0] < image.width() && nouveau_point[1] >= 0 && nouveau_point[1] < image.height())
            {
                copie.pixel(x, y) = image.pixel(nouveau_point[0], nouveau_point[1]);
            }
            else
            {
               copie.pixel(x, y) = glm::vec3{0.f};
            }
        }
    }
    image = copie;
}


void exo24_convolutions(sil::Image& image)
{
    int f = 8; //nombre de pixels utilisés pour floutter un pixel
    sil::Image copie = image;
    for (int x1{0}; x1<image.width();x1++)
    {
        for (int y1{0}; y1 < image.height(); y1++)
        {
            float sum_r{0};
            float sum_g{0};
            float sum_b{0}; 
            for (int x2{x1-f}; x2<=x1+f;x2++)
            {
                for (int y2{y1-f}; y2 <= y1+f; y2++)
                {
                    glm::vec2 point1{x1,y1};
                    glm::vec2 point2{x2,y2};
                    if (x2 >= 0 & y2 >= 0 and x2 < image.width() & y2<image.height())
                    {
                        sum_r += image.pixel(x2,y2).r;
                        sum_g += image.pixel(x2,y2).g;
                        sum_b += image.pixel(x2,y2).b;
                    }
                }
            }
            copie.pixel(x1,y1).r = sum_r / ((2*f+1)*(2*f+1.f));
            copie.pixel(x1,y1).g = sum_g / ((2*f+1)*(2*f+1.f));
            copie.pixel(x1,y1).b = sum_b / ((2*f+1)*(2*f+1.f));
        }
    }
    image = copie;
}

void exo25_outline(sil::Image& image)
{
    int f = 1; //nombre de pixels utilisés pour floutter un pixel
    sil::Image copie = image;
    for (int x1{0}; x1<image.width();x1++)
    {
        for (int y1{0}; y1 < image.height(); y1++)
        {
            float sum_r{0};
            float sum_g{0};
            float sum_b{0}; 
            for (int x2{x1-f}; x2<=x1+f;x2++)
            {
                for (int y2{y1-f}; y2 <= y1+f; y2++)
                {
                    glm::vec2 point1{x1,y1};
                    glm::vec2 point2{x2,y2};
                    if (x2 >= 0 && y2 >= 0 && x2 < image.width() && y2<image.height())
                    {
                        if (x2 == x1 && y2 == y1){
                            sum_r += 8*image.pixel(x2,y2).r;
                            sum_g += 8*image.pixel(x2,y2).g;
                            sum_b += 8*image.pixel(x2,y2).b;
                        }
                        else
                        {
                            sum_r -= image.pixel(x2,y2).r;
                            sum_g -= image.pixel(x2,y2).g;
                            sum_b -= image.pixel(x2,y2).b;
                        }
                    }
                }
            }
            copie.pixel(x1,y1).r = sum_r ;
            copie.pixel(x1,y1).g = sum_g ;
            copie.pixel(x1,y1).b = sum_b ;
        }
    }
    image = copie;
}



void exo28_k_moyenne(sil::Image& image3)
{
    int k = 16;
    std::vector<glm::vec3> centers;
    for (int i = 0; i < k; i++)
    {
        int x = random_int(0, image3.width() - 1);
        int y = random_int(0, image3.height() - 1);
        centers.push_back(image3.pixel(x, y));
    }
    for (int i{0}; i<20; i++)
    {
        std::vector<glm::vec3> moyenne(k, glm::vec3{0.f});
        std::vector<int> nb_centers(k, 0);
        for (glm::vec3& color : image3.pixels())
        {
            int best{0};
            float best_dist = glm::distance(color, centers[0]);
            for (int j = 0; j<k; j++)
            {
                if (glm::distance(color, centers[j])<best_dist)
                {
                    best = j;
                    best_dist = glm::distance(color, centers[j]);
                }
            }
            moyenne[best] += color;
            nb_centers[best] += 1;
        } 
        for (int j{0}; j<k; j++)
        {
            centers[j] = moyenne[j] / static_cast<float>(nb_centers[j]);
        }
    }
    for (glm::vec3& color : image3.pixels())
    {
        int best{0};
            float best_dist = glm::distance(color, centers[0]);
            for (int j = 0; j<k; j++)
            {
                if (glm::distance(color, centers[j])<best_dist)
                {
                    best = j;
                    best_dist = glm::distance(color, centers[j]);
                }
            }
        color = centers[best];
    }
}




int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image image2{500/*width*/, 500/*height*/}; //dimensions à changer en fonction de la fonction à utiliser
    sil::Image image3{"images/photo.jpg"};

    
    exo25_outline(image);

    image.save("output/pouet.png");

    
}