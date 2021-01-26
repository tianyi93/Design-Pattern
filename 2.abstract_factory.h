//
// Created by Tianyi Zhang on 10/18/20.
//

#ifndef DESIGN_PATTERN_2_ABSTRACT_FACTORY_H
#define DESIGN_PATTERN_2_ABSTRACT_FACTORY_H
#include <string>
#include <memory>
class Button{
public:
    virtual void setOSName(std::string osName) = 0;
    virtual void setType(std::string type) = 0;
    virtual std::string getOSName() = 0;
    virtual std::string getType() = 0;
};

class Window{
public:
    virtual void setOSName(std::string osName) = 0;
    virtual void setWidth(int width) = 0;
    virtual std::string getOSName() = 0;
    virtual int getWidth() = 0;
};

class ButtonImpl : public Button{
public:
    void setOSName(std::string osName) override{
        this->osName = osName;
    }
    void setType(std::string type) override{
        this->type = type;
    }
    std::string getOSName() override{
        return osName;
    }
    std::string getType() override{
        return type;
    }
private:
    std::string osName;
    std::string type;
};

class MacButton : public ButtonImpl{
public:
    MacButton(){
        setOSName("MacOS ");
        setType("square ");
    }
};

class WindowsButton : public ButtonImpl{
public:
    WindowsButton(){
        setOSName("Windows ");
        setType("rectangle ");
    }
};

class WindowImpl: public Window{
public:
    void setOSName(std::string osName) override{
        this->osName = osName;
    }
    void setWidth(int width) override{
        this->width = width;
    }
    std::string getOSName() override{
        return osName;
    }
    int getWidth() override{
        return width;
    }
private:
    std::string osName;
    int width;
};

class MacWindow : public WindowImpl{
public:
    MacWindow(){
        setOSName("Mac ");
        setWidth(5);
    }
};

class WindowsWindow: public WindowImpl{
public:
    WindowsWindow(){
        setOSName("Windows ");
        setWidth(10);
    }
};

class UIFactory{
    virtual std::shared_ptr<Button> buildButton() = 0;
    virtual std::shared_ptr<Window> buildWindow() = 0;
};

class MacUIFactory: public UIFactory{
public:
    std::shared_ptr<Button> buildButton() override{
        std::shared_ptr<Button> button =  std::shared_ptr<MacButton>(new MacButton());
        return button;
    }
    std::shared_ptr<Window> buildWindow() override {
        std::shared_ptr<Window> window = std::shared_ptr<MacWindow>(new MacWindow());
        return window;
    }
};

class WindowsUIFactory: public UIFactory{
public:
    std::shared_ptr<Button> buildButton() override{
        std::shared_ptr<Button> button =  std::shared_ptr<WindowsButton>(new WindowsButton());
        return button;
    }
    std::shared_ptr<Window> buildWindow() override {
        std::shared_ptr<Window> window = std::shared_ptr<WindowsWindow>(new WindowsWindow());
        return window;
    }
};
#endif //DESIGN_PATTERN_2_ABSTRACT_FACTORY_H
