#include<iostream>
using namespace std;

//////////////////////////////////////
//
// Structure name: nodeS
// Input:          Generic data,Pointer
// Description:    It is used for  SinglyLL & SinglyCL
// Author:         Mahesh Rajendra Parshuramkar
// Date:           20/11/2021
//
//////////////////////////////////////

template<typename T>
struct nodeS
{
	T data;
	struct nodeS * next;
};

//////////////////////////////////////
//
// Structure name: nodeD
// Input:          Generic data,Pointer,Pointer
// Description:    It is used for  DoublyLL & DoublyCL
// Author:         Mahesh Rajendra Parshuramkar
// Date:           20/11/2021
//
//////////////////////////////////////

template<typename T>
struct nodeD
{
	T data;
	struct nodeD * next;
	struct nodeD * prev;
};

//////////////////////////////////////
//
// Class name:         SinglyLL
// Characteristics:    Pointer,Integer
// Behaviour:          SinglyLL(),Display(),Count(),
//                     InsertFirst(),InsertLast(),InsertAtPos(),
//                     DeleteFirst(),DeleteLast(),DeleteAtPos(), 
// Description:        It is used to perform certain things on SinglyLL 
// Author:             Mahesh Rajendra Parshuramkar
// Date:               20/11/2021
//
//////////////////////////////////////

template<class T>
class SinglyLL
{
	private:
	  nodeS<T> * first;
	  int size;
	  
	public:
	   SinglyLL();
	   void InsertFirst(T );
	   void InsertLast(T );
	   void InsertAtPos(T ,int );
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int );
	   void Display();
	   int Count();
};

//////////////////////////////////////
//
// Class name:         SinglyCL
// Characteristics:    Pointer,Pointer,Integer
// Behaviour:          SinglyCL(),Display(),Count(),
//                     InsertFirst(),InsertLast(),InsertAtPos(),
//                     DeleteFirst(),DeleteLast(),DeleteAtPos(), 
// Description:        It is used to perform certain things on SinglyCL 
// Author:             Mahesh Rajendra Parshuramkar
// Date:               20/11/2021
//
//////////////////////////////////////

template<class T>
class SinglyCL
{
	private:
	  struct nodeS<T> * first;
	  struct nodeS<T> * last;
	  int size;
	  
	public:
	  SinglyCL();
	  void InsertFirst(T );
	  void InsertLast(T );
	  void InsertAtPos(T ,int );
	  void DeleteFirst();
	  void DeleteLast();
	  void DeleteAtPos(int );
	  void Display();
	  int Count();
};

//////////////////////////////////////
//
// Class name:         DoublyLL
// Characteristics:    Pointer,Integer
// Behaviour:          DoublyLL(),Display(),Count(),
//                     InsertFirst(),InsertLast(),InsertAtPos(),
//                     DeleteFirst(),DeleteLast(),DeleteAtPos(), 
// Description:        It is used to perform certain things on DoublyLL 
// Author:             Mahesh Rajendra Parshuramkar
// Date:               20/11/2021
//
//////////////////////////////////////

template<class T>
class DoublyLL
{
	private:
	  struct nodeD<T> * first;
	  int size;
	  
	public:
	   DoublyLL();
	   void InsertFirst(T );
	   void InsertLast(T );
	   void InsertAtPos(T ,int );
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int );
	   void Display();
	   int Count();
};

//////////////////////////////////////
//
// Class name:         DoublyCL
// Characteristics:    Pointer,Integer
// Behaviour:          DoublyCL(),Display(),Count(),
//                     InsertFirst(),InsertLast(),InsertAtPos(),
//                     DeleteFirst(),DeleteLast(),DeleteAtPos(), 
// Description:        It is used to perform certain things on DoublyCL 
// Author:             Mahesh Rajendra Parshuramkar
// Date:               20/11/2021
//
//////////////////////////////////////

template<class T>
class DoublyCL
{
	private:
	  struct nodeD<T> * first;
	  struct nodeD<T> * last;
	  int size;
	  
	public:
	  DoublyCL();
	  void InsertFirst(T );
	  void InsertLast(T );
	  void InsertAtPos(T ,int );
	  void DeleteFirst();
	  void DeleteLast();
	  void DeleteAtPos(int );
	  void Display();
	  int Count();
};


     //************************SinglyLL**********************************//

//////////////////////////////////////
//
// Function name: SinglyLL
// Input:         
// Output:        
// Description:   It is used to initialize the characteristics of Class
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
SinglyLL<T> :: SinglyLL()
{
	first = NULL;
	size = 0;
} 

//////////////////////////////////////
//
// Function name: InsertFirst
// Input:         Generic data
// Output:        Node gets inserted at first position
// Description:   It is used to insert the node in SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: InsertFirst(T no)
{
	nodeS<T> * newn = new nodeS<T>;
		
	newn->data = no;
    newn->next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

//////////////////////////////////////
//
// Function name: InsertLast
// Input:         Generic data
// Output:        Node gets inserted at Last position
// Description:   It is used to insert the node in SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: InsertLast(T no)
{
	nodeS<T> * newn = new nodeS<T>;
		
	newn->data = no;
    newn->next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		nodeS<T> * temp = first;
			
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;
}

//////////////////////////////////////
//
// Function name: InsertAtPos
// Input:         Generic data,Integer
// Output:        Node gets inserted at desired position
// Description:   It is used to insert the node in SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: InsertAtPos(T no,int iPos)
{
	nodeS<T> * temp = first;
		
	if((iPos < 1) || (iPos > size+1))
	{
		return;
	}
		
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size)
	{
		InsertLast(no);
	}
	else
	{
		nodeS<T> * newn = new  nodeS<T>;
		int i = 0;
			
		newn->data = no;
		newn->next = NULL;
			
		for(i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
			
		size++;
	}
}  

//////////////////////////////////////
//
// Function name: DeleteFirst
// Input:         
// Output:        Node gets deleted from first position
// Description:   It is used to delete the node from SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: DeleteFirst()
{
	nodeS<T> * temp = first;
		
	if(first != NULL)
	{
		first = first->next;
		delete temp;
			
		size--;
	}
}

//////////////////////////////////////
//
// Function name: DeleteLast
// Input:         
// Output:        Node gets deleted from Last position
// Description:   It is used to delete the node from SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: DeleteLast()
{
	nodeS<T> * temp = first;
		
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
		size--;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		size--;
	}
}

//////////////////////////////////////
//
// Function name: DeleteAtPos
// Input:         
// Output:        Node gets deleted from desired position
// Description:   It is used to delete the node from SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void  SinglyLL<T> :: DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size+1))
	{
		return;
	}
		
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		nodeS<T> * temp = first;
		nodeS<T> * targated = NULL;
		int i = 0;
			
		for(i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		targated = temp->next;;
		temp->next = targated->next;
		free(targated);
			
		size--;
	}
}

//////////////////////////////////////
//
// Function name: Display
// Input:         
// Output:        Displays all the data
// Description:   It is used to display all the data of SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
void SinglyLL<T> :: Display()
{
	nodeS<T> * temp = first;
	  
	while(temp != NULL)
	{
	   cout<<temp->data<<"\t";
	   temp = temp->next;
	}
	cout<<"\n";
}

//////////////////////////////////////
//
// Function name: Count
// Input:         
// Output:        Counts the nodes
// Description:   It is used to count the number of nodes of SinglyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>	
int SinglyLL<T> :: Count()
{
	return size;
}


     //************************SINGLYCL**********************************//

//////////////////////////////////////
//
// Function name: SinglyCL
// Input:         
// Output:        
// Description:   It is used to initialize the characteristics of Class
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
SinglyCL<T> :: SinglyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

//////////////////////////////////////
//
// Function name: InsertFirst
// Input:         Generic data
// Output:        Node gets inserted at first position
// Description:   It is used to insert the node in SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T> 
void SinglyCL<T> :: InsertFirst(T no)
{
	struct nodeS<T> * newn = new struct nodeS<T>;
		  
	newn->data = no;
	newn->next = NULL;
		
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
		
	last->next = first;
	size++;
}

//////////////////////////////////////
//
// Function name: InsertLast
// Input:         Generic data
// Output:        Node gets inserted at Last position
// Description:   It is used to insert the node in SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void SinglyCL<T> ::InsertLast(T no)
{
	struct nodeS<T> * newn = new struct nodeS<T>;
		  
	newn->data = no;
	newn->next = NULL;
		
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		last = newn;
	}
		
	last->next = first;
	size++;
}

//////////////////////////////////////
//
// Function name: InsertAtPos
// Input:         Generic data,Integer
// Output:        Node gets inserted at desired position
// Description:   It is used to insert the node in SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T> 
void SinglyCL<T> :: InsertAtPos(T no,int iPos)
{
	if((iPos < 1) || (iPos > size+1))
	{
		return;
	}
		  
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct nodeS<T> * newn = new struct nodeS<T>;
		struct nodeS<T> * temp = first;
			
		newn->data = no;
		newn->next = NULL;
			
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
			
		size++;
	}
}

//////////////////////////////////////
//
// Function name: DeleteFirst
// Input:         
// Output:        Node gets deleted from first position
// Description:   It is used to delete the node from SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		last->next = first;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteLast
// Input:         
// Output:        Node gets deleted from Last position
// Description:   It is used to delete the node from SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T> 
void SinglyCL<T> :: DeleteLast()
{
	struct nodeS<T> * temp = first;
		
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		while(temp->next != last)
		{
			temp = temp->next;
		}
		delete last;
		last = temp;
			
		last->next = first;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteAtPos
// Input:         
// Output:        Node gets deleted from desired position
// Description:   It is used to delete the node from SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T> 
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
	if((iPos < 1) || (iPos > size))
	{
		return;
	}
		  
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct nodeS<T> * temp = first;
			
		for(int i = 1;i < iPos-1;i++)
		{
			temp = temp->next;
		}
		struct nodeS<T> * targated = temp->next;
		temp->next = targated->next;
		delete targated;
			
		size--;
	}
}

//////////////////////////////////////
//
// Function name: Display
// Input:         
// Output:        Displays all the data
// Description:   It is used to display all the data of SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void SinglyCL<T> :: Display()
{
	struct nodeS<T> * temp = first;
		  
	if((first == NULL) && (last == NULL))
	{
		return;
	}
		  
	do
	{
		cout<<temp->data<<"\t";
        temp =temp->next;			
	}while(temp != last->next);
		  
	cout<<"\n";
}

//////////////////////////////////////
//
// Function name: Count
// Input:         
// Output:        Counts the nodes
// Description:   It is used to count the number of nodes of SinglyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
int SinglyCL<T> :: Count()
{
	return size;
}


     //************************DOUBLYLL**********************************//



//////////////////////////////////////
//
// Function name: DoublyLL
// Input:         
// Output:        
// Description:   It is used to initialize the characteristics of Class
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
DoublyLL<T> :: DoublyLL()
{
	first = NULL;
	size = 0;
}

//////////////////////////////////////
//
// Function name: InsertFirst
// Input:         Generic data
// Output:        Node gets inserted at first position
// Description:   It is used to insert the node in DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
	struct nodeD<T> * newn = new struct nodeD<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	size++;
}

//////////////////////////////////////
//
// Function name: InsertLast
// Input:         Generic data
// Output:        Node gets inserted at Last position
// Description:   It is used to insert the node in DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
	struct nodeD<T> * newn = new struct nodeD<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		struct nodeD<T> * temp = first;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
	size++;
}

//////////////////////////////////////
//
// Function name: InsertAtPos
// Input:         Generic data,Integer
// Output:        Node gets inserted at desired position
// Description:   It is used to insert the node in DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertAtPos(T no,int ipos)
{
	if((ipos < 1) || (ipos > size+1))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct nodeD<T> * temp = first;
		struct nodeD<T> * newn = new struct nodeD<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		
		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		
		size++;
	}
}

//////////////////////////////////////
//
// Function name: DeleteFirst
// Input:         
// Output:        Node gets deleted from first position
// Description:   It is used to delete the node from DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = NULL;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteLast
// Input:         
// Output:        Node gets deleted from Last position
// Description:   It is used to delete the node from DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteLast()
{
	if(first == NULL)
	{
		return;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		struct nodeD<T> * temp = first;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete temp;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteAtPos
// Input:         
// Output:        Node gets deleted from desired position
// Description:   It is used to delete the node from DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		struct nodeD<T> * temp = first;
		
		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		
		size--;
	}
}

//////////////////////////////////////
//
// Function name: Display
// Input:         
// Output:        Displays all the data
// Description:   It is used to display all the data of DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyLL<T> :: Display()
{
	struct nodeD<T> * temp = first;
	
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

//////////////////////////////////////
//
// Function name: Count
// Input:         
// Output:        Counts the nodes
// Description:   It is used to count the number of nodes of DoublyLL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
int DoublyLL<T> :: Count()
{
	return size;
}



     //************************DoublyCL**********************************//


//////////////////////////////////////
//
// Function name: DoublyCL
// Input:         
// Output:        
// Description:   It is used to initialize the characteristics of Class
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
DoublyCL<T> :: DoublyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

//////////////////////////////////////
//
// Function name: InsertFirst
// Input:         Generic data
// Output:        Node gets inserted at first position
// Description:   It is used to insert the node in DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
	struct nodeD<T> * newn = new struct nodeD<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
        first = newn;		
	}
	
	last->next = first;   
	first->prev = last;  
	size++;
}

//////////////////////////////////////
//
// Function name: InsertLast
// Input:         Generic data
// Output:        Node gets inserted at Last position
// Description:   It is used to insert the node in DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
	struct nodeD<T> * newn = new struct nodeD<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}
	
	last->next = first;
	first->prev = last;
	size++;
}

//////////////////////////////////////
//
// Function name: InsertAtPos
// Input:         Generic data,Integer
// Output:        Node gets inserted at desired position
// Description:   It is used to insert the node in DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertAtPos(T no,int ipos)
{
	if((ipos < 1) || (ipos > size+1))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		struct nodeD<T> * newn = new struct nodeD<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		struct nodeD<T> * temp = first;
		
		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		
		size++;
	}
}

//////////////////////////////////////
//
// Function name: DeleteFirst
// Input:         
// Output:        Node gets deleted from first position
// Description:   It is used to delete the node from DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		
		last->next = first;
	    first->prev = last;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteLast
// Input:         
// Output:        Node gets deleted from Last position
// Description:   It is used to delete the node from DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last->prev;
		delete last->next;
		
		last->next = first;
	    first->prev = last;
	}
	size--;
}

//////////////////////////////////////
//
// Function name: DeleteAtPos
// Input:         
// Output:        Node gets deleted from desired position
// Description:   It is used to delete the node from DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		struct nodeD<T> * temp = first;
		
		for(int i = 1;i <ipos-1;i++)
		{
			temp = temp->next;
		}
		
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

		size--;
	}
}

//////////////////////////////////////
//
// Function name: Display
// Input:         
// Output:        Displays all the data
// Description:   It is used to display all the data of DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
void DoublyCL<T> :: Display()
{
	struct nodeD<T> * temp = first;
	
	for(int i = 1; i <= size; i++)      
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

//////////////////////////////////////
//
// Function name: Count
// Input:         
// Output:        Counts the nodes
// Description:   It is used to count the number of nodes of DoublyCL
// Author:        Mahesh Rajendra Parshuramkar
// Date:          20/11/2021
//
//////////////////////////////////////

template<class T>
int DoublyCL<T> :: Count()
{
	return size;
}



      //*************************Thank You*************************//