#include <iostream>
#include "my_templates.h"
#include "my_classes.h"

int main()
{
	Queue<Worker*> first_queue(3);

	Waiter b("Borya", 100300, 2);
	b.Show();
	Singer c("Canya", 100400, 1);
	c.Show();
	SingingWaiter d("Daniel", 100500, 3, 2, 5);
	d.Show();

	first_queue.add(&b);
	first_queue.add(&c);
	first_queue.add(&d);

	Worker* some;
	bool is_not_queue_empty;
	
	do
	{
		std::cout << "Delete from queue first element and transport if to another element." << std::endl;
		is_not_queue_empty =  first_queue.delete_element(some);
		if(is_not_queue_empty) 
			some->Show();
	} while (is_not_queue_empty);

	

	return 0;
}