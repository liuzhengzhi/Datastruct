#ifndef __MYLIST_H__
#define __MYLIST_H__

struct list_base
{
	list_base * next;
	list_base * prev;	
};

template<typename _Tp>
struct list_element : public list_base 
{
	_Tp element;	
};

template<typename _Tp>
class mylist {
public:
	mylist();
	~mylist();
	mylist(const mylist &cpy);
	
private:
};

mylist::mylist() {
}

mylist::~mylist() {
}

mylist::mylist(gconst mylist &cpy) {
}
#endif /* __MYLIST_H__ */
