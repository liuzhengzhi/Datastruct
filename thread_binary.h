#ifndef __THREAD_BINARY_H__
#define __THREAD_BINARY_H__

typedef struct binary_node* binary_pointer;
struct binary_node
{
	binary_pointer left_child;
	binary_pointer right_child;
	bool left_thread;
	bool right_thread;
	char data;
};

binary_pointer creat_binary();
void binary_show(binary_pointer ptr);
void show_thread(binary_pointer ptr);
binary_pointer show_pre(binary_pointer ptr);
void tinorder(binary_pointer ptr);
bool isempty(binary_pointer ptr);
#endif /* __THREAD_BINARY_H__ */
