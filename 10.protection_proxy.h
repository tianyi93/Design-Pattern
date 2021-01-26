//
// Created by Tianyi Zhang on 12/24/20.
//

#ifndef DESIGN_PATTERN_10_PROTECTION_PROXY_H
#define DESIGN_PATTERN_10_PROTECTION_PROXY_H
#include <string>
#include <iostream>
#include <memory>

struct PersonBean{
    virtual std::string getName() = 0;
    virtual std::string getGender() = 0;
    virtual int getHotRating() = 0;

    virtual void setName(std::string const& name) = 0;
    virtual void setGender(std::string const& gender) = 0;
    virtual void setHotRating(int rating) = 0;
};

struct PersonBeanImpl : public PersonBean{
    std::string getName() override{
        return this->name;
    }
    std::string getGender() override{
        return this->gender;
    }
    int getHotRating() override{
        return this->rating / this->ratingCount;
    }

    void setName(std::string const& name) override{
        this->name = name;
    }
    void setGender(std::string const& gender) override{
        this->gender = gender;
    }
    void setHotRating(int rating) override{
        this->rating+=rating;
        ratingCount++;
    }
private:
    std::string name;
    std::string gender;
    int rating{0};
    int ratingCount{0};
};

struct PersonBeanOwnerProxy : public PersonBean{
    PersonBeanOwnerProxy(std::shared_ptr<PersonBeanImpl> personBean){
        this->personBean = personBean;
    }
    std::string getName() override{
        return personBean->getName();
    }
    std::string getGender() override{
        return personBean->getGender();
    }
    int getHotRating() override{
        return personBean->getHotRating();
    }

    void setName(std::string const& name) override{
        personBean->setName(name);
    }
    void setGender(std::string const& gender) override{
        personBean->setGender(gender);
    }
    void setHotRating(int rating) override{
        std::cout<<"This function cannot be accessed by Person Bean owner, your hot rating is decided by others"<<std::endl;
    }
private:
    std::shared_ptr<PersonBeanImpl> personBean;
};

struct PersonBeanNonOwnerProxy : public PersonBean{
    PersonBeanNonOwnerProxy(std::shared_ptr<PersonBeanImpl> personBean){
        this->personBean = personBean;
    }
    std::string getName() override{
        return personBean->getName();
    }
    std::string getGender() override{
        return personBean->getGender();
    }
    int getHotRating() override{
        return personBean->getHotRating();
    }

    void setName(std::string const& name) override{
        std::cout<<"This function cannot be accessed by Person Bean Non Owner, you cannot change others' profile"<<std::endl;
    }
    void setGender(std::string const& gender) override{
        std::cout<<"This function cannot be accessed by Person Bean Non Owner, you cannot change others' profile"<<std::endl;
    }
    void setHotRating(int rating) override{
        personBean->setHotRating(rating);
    }
private:
    std::shared_ptr<PersonBeanImpl> personBean;
};

PersonBeanOwnerProxy getOwnerProxy(std::shared_ptr<PersonBeanImpl> personBean){
    return PersonBeanOwnerProxy(personBean);
}

PersonBeanNonOwnerProxy getNonOwnerProxy(std::shared_ptr<PersonBeanImpl> personBean){
    return PersonBeanNonOwnerProxy(personBean);
}
#endif //DESIGN_PATTERN_10_PROTECTION_PROXY_H
