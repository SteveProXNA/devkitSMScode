#ifndef _MAP_OBJECT_H_
#define _MAP_OBJECT_H_

typedef struct tag_struct_map_object
{
	unsigned char *level_data;
	unsigned char *next_row;
	unsigned char background_y;
	unsigned char lines_before_next;
	unsigned char scroll_y;

} struct_map_object;


#endif//_MAP_OBJECT_H_