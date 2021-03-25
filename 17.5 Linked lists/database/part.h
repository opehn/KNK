#ifndef PART_H
# define PART_H

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
}

#endif
