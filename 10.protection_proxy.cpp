//
// Created by Tianyi Zhang on 12/24/20.
//

#include "10.protection_proxy.h"
int main(){
    std::shared_ptr<PersonBeanImpl> personBeanImpl = std::make_shared<PersonBeanImpl>();
    auto ownerProxy = getOwnerProxy(personBeanImpl);
    ownerProxy.setName("Mike");
    ownerProxy.setGender("Male");
    ownerProxy.setHotRating(10);

    auto nonOwnerProxy = getNonOwnerProxy(personBeanImpl);
    nonOwnerProxy.setName("Amy");
    nonOwnerProxy.setGender("Female");
    nonOwnerProxy.setHotRating(10);

    std::cout<<ownerProxy.getName()<<","<<ownerProxy.getGender()<<","<<ownerProxy.getHotRating()<<std::endl;
    std::cout<<nonOwnerProxy.getName()<<","<<nonOwnerProxy.getGender()<<","<<nonOwnerProxy.getHotRating()<<std::endl;
    return 0;
}