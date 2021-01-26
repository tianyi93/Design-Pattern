//
// Created by Tianyi Zhang on 12/22/20.
//

#ifndef DESIGN_PATTERN_10_VIRTUAL_PROXY_H
#define DESIGN_PATTERN_10_VIRTUAL_PROXY_H
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

struct Icon{
    virtual int getIconWidth() = 0;
    virtual int getIconHeight() = 0;
    virtual void paintIcon() = 0;
};
struct Image{
    Image(int width, int height, std::string const& content) : Width(width), Height(height), Content(content){}
    int Width;
    int Height;
    std::string Content;
};
struct ImageServer{
    static Image getImage(int id){
            return Image(id,id,"Image : "+std::to_string(id));
    }
};
struct ImageIcon: public Icon{
    ImageIcon(int id) : image(ImageServer::getImage(id)){
        std::chrono::seconds dura(3);
        std::this_thread::sleep_for( dura );
    }
    int getIconWidth(){
        return image.Width;
    }
    int getIconHeight(){
        return image.Height;
    }
    void paintIcon(){
        std::cout<<"This is a window, width :"<<getIconWidth()<<", height : "<<getIconHeight()<<std::endl;
        std::cout<<image.Content<<std::endl;
    };
private:
    Image image;
};

struct ImageProxy : public Icon{
    ImageProxy(int id){
        imageIcon = nullptr;
        this->id = id;
    }
    int getIconWidth(){
        if(imageIcon != nullptr)
            return imageIcon->getIconWidth();
        else
            return 5;
    }
    int getIconHeight(){
        if(imageIcon != nullptr)
            return imageIcon->getIconHeight();
        else
            return 5;
    }
    void paintIcon(){
        if(imageIcon == nullptr){
            std::cout<<"This is a window, width :"<<getIconWidth()<<", height : "<<getIconHeight()<<std::endl;
            std::cout<<"Loading Image, please wait..."<<std::endl;
            imageIcon = std::make_unique<ImageIcon>(id);
            paintIcon();
        }else{
            std::cout<<"Refreshed..........."<<std::endl;
            imageIcon->paintIcon();
        }
    };
private:
    std::unique_ptr<ImageIcon> imageIcon;
    int id;
};


#endif //DESIGN_PATTERN_10_VIRTUAL_PROXY_H
