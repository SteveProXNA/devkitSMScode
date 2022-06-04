#ifndef _SCROLL_OBJECT_H_
#define _SCROLL_OBJECT_H_

typedef struct tag_struct_scroll_object
{
	unsigned int scroll;
	unsigned int height;
	unsigned int size;

	unsigned char scrollleft;
	unsigned char scrollRight;
	unsigned char scrollRightDivided8;

} struct_scroll_object;

#endif//_SCROLL_OBJECT_H_