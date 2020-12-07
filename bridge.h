//
// Created by Tianyi Zhang on 12/6/20.
//

#ifndef DESIGN_PATTERN_BRIDGE_H
#define DESIGN_PATTERN_BRIDGE_H
#include <string>
#include <memory>
#include <iostream>

struct IResource{
    virtual std::string snippet() const= 0;
    virtual ~IResource(){}
};

struct IView{
    virtual void show() = 0;
    virtual ~IView(){}
};

struct Artist{
    std::string bio() const{
        return "Artist bio info. Artist full bio info";
    }
};

struct Book{
    std::string coverInfo() const{
        return "Book cover info. Book full cover info";
    }
};

struct ArtistResource : public IResource{
    ArtistResource(Artist const& artist1): artist(artist1){}
    std::string snippet() const override{
        return artist.bio();
    }
    Artist artist;
};

struct BookResource : public IResource{
    BookResource(Book const& book1): book(book1){}
    std::string snippet() const override{
        return book.coverInfo();
    }
    Book book;
};

struct ShortView : public IView{
    ShortView(std::shared_ptr<IResource> resource1):resource(resource1){}
     void show() override{
        std::string content = resource->snippet();
        int pos = content.find('.');
        std::cout<<"shortView : "<< content.substr(0, pos) << std::endl;
    }
    std::shared_ptr<IResource> resource;
};

struct FullView : public IView{
    FullView(std::shared_ptr<IResource> resource1):resource(resource1){}
    void show() override{
        std::string content = resource->snippet();
        std::cout<<"Full View : "<<content<<std::endl;
    }
    std::shared_ptr<IResource> resource;
};

#endif //DESIGN_PATTERN_BRIDGE_H
