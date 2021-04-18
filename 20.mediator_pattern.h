//
// Created by Tianyi Zhang on 4/16/21.
//

#ifndef DESIGN_PATTERN_20_MEDIATOR_PATTERN_H
#define DESIGN_PATTERN_20_MEDIATOR_PATTERN_H
#include <memory>
#include <iostream>

struct Mediator;
struct Colleague : std::enable_shared_from_this<Colleague>{
    Colleague(std::shared_ptr<Mediator> mediator):mediator_(mediator){};
protected:
    void notifyChange();
private:
    std::shared_ptr<Mediator> mediator_;
};
struct Mediator : std::enable_shared_from_this<Mediator>{
    virtual void ColleagueChanged(std::shared_ptr<Colleague> changedColleague) = 0;

    virtual ~Mediator(){};
};

void Colleague::notifyChange(){
    mediator_->ColleagueChanged(shared_from_this());
}

enum Color{
    White, Black
};
std::string toString(Color color){
    if(color == Color::White)
        return "White";
    else
        return "Black";
}
struct BackGround : public Colleague{
    BackGround(std::shared_ptr<Mediator> mediator) : Colleague(mediator){
        color_ = Color::White;
    }
    void setBackGroundColor(Color color){
        if(color != color_) {
            color_ = color;
            std::cout<<"background color set to "<< toString(color)<<std::endl;
            notifyChange();
        }
    }
    Color getBackGroundColor(){
        return color_;
    }
private:
    Color color_;
    //...other attributes
};

struct Font : public Colleague{
    Font(std::shared_ptr<Mediator> mediator) : Colleague(mediator){
        color_ = Color::Black;
    }
    void setFontColor(Color color){
        if(color != color_) {
            color_ = color;
            std::cout<<"font color set to "<< toString(color)<<std::endl;
            notifyChange();
        }
    }
    Color getFontColor(){
        return color_;
    }
private:
    Color color_;
    //...other attributes
};

struct DisplayMediator : public Mediator{
    DisplayMediator() = default;
    DisplayMediator& withColleague(std::shared_ptr<BackGround> background, std::shared_ptr<Font> font){
        background_ = background;
        font_ = font;
        return *this;
    }
    void ColleagueChanged(std::shared_ptr<Colleague> changedColleague) override{
        if(changedColleague == background_){
            if(background_->getBackGroundColor() == Color::White)
                font_->setFontColor(Color::Black);
            else if(background_->getBackGroundColor() == Color::Black)
                font_->setFontColor(Color::White);

        }else if(changedColleague == font_){
            if(font_->getFontColor() == Color::White)
                background_->setBackGroundColor(Color::Black);
            else
                background_->setBackGroundColor(Color::White);
        }
    }

private:
    std::shared_ptr<BackGround> background_;
    std::shared_ptr<Font> font_;
};

#endif //DESIGN_PATTERN_20_MEDIATOR_PATTERN_H
