//
// Created by Tianyi Zhang on 12/6/20.
//
#include "bridge.h"
int main(){
    Artist artist;
    std::shared_ptr<ArtistResource> artistResource = std::make_shared<ArtistResource>(artist);
    ShortView shortViewArtist(artistResource);
    FullView fullViewArtist(artistResource);
    shortViewArtist.show();
    fullViewArtist.show();

    Book book;
    std::shared_ptr<BookResource> bookResource = std::make_shared<BookResource>(book);
    ShortView shortViewBook(bookResource);
    FullView fullViewBook(bookResource);
    shortViewBook.show();
    fullViewBook.show();

    return 0;
}
