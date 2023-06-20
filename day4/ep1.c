#include <stdio.h>

struct Box {
    int length;
    int width;
    int height;
};


int calculateVolume(struct Box* boxPtr) {
    int volume = boxPtr->length * boxPtr->width * boxPtr->height;
    return volume;
}


int calculateSurfaceArea(struct Box* boxPtr) {
    int surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    return surfaceArea;
}

int main() {
    struct Box myBox;
    myBox.length = 5;
    myBox.width = 3;
    myBox.height = 4;

    struct Box* boxPtr = &myBox;

    
    int volume = calculateVolume(boxPtr);
    int surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume of the box: %d\n", volume);
    printf("Surface area of the box: %d\n", surfaceArea);

    return 0;
}
