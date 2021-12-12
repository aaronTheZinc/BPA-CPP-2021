#include <iostream>
#include <string>

struct OffSpring
{
    std::string name;
    uint age;
};

class DeerFamilyTree
{

private:
    typedef struct node
    {
        int ref;
        OffSpring data;
        node *next;
    } * nodePtr;

    nodePtr head;
    nodePtr current;
    nodePtr temp;

public:
    void init()
    {
        head = NULL;
        current = NULL;
        temp = NULL;
    }
    void display()
    {
        if (head != NULL)
        {
            current = head;
            std::string childImpl = "no child";
            while (current != NULL)
            {
                node n = *current;
                if (current->next != NULL)
                {
                    childImpl = "child -> " + std::to_string(n.next->ref) + " child " + n.next->data.name;
                }
                std::cout << "ref -> " << n.ref << " " + n.data.name + " " << n.data.age << childImpl << std::endl;
                current = current->next;
            }
        }
        else
        {
            std::cout << "no fawns in list." << std::endl;
        }
    };
    void birth_fawn(OffSpring data, int ref)
    {
        nodePtr n = new node;
        n->next = NULL;
        n->ref = ref;
        n->data = data;

        if (head != NULL)
        {
            current = head;
            while (current->next != NULL)
            {
                current = current->next;
            };
            current->next = n;
        }
        else
        {
            head = n;
        };
    };

    void remove_fawn(int ref)
    {
        nodePtr refDel;
        temp = head;
        current = head;

        while (current != NULL && current->ref != ref)
        {
            temp = current;
            current = current->next;
        };
        if (current == NULL)
        {
            std::cout << ref << "could not be identified" << std::endl;
        }
        else
        {
            std::cout << "reached this block!" << std::endl;

            refDel = current;
            current = current->next;
            temp->next = current;

            delete refDel;

            std::cout << ref << " <-was deleted" << std::endl;
        }
    };
    int number_of_fawns()
    {
        int count = 0;
        if (head != NULL)
        {

            current = head;
            nodePtr temporary = current;

            while (temporary->next != NULL)
            {
                temporary = temporary->next;
                count++;
            }
        }
        else
        {
            std::cout << "no fawns in list." << std::endl;
        }

        return count;
    }
    void clear()
    {
        head = NULL;
    }
};

int main()
{
    int num_of_generations = 30;
    typedef OffSpring Fawn;
    DeerFamilyTree Family;

    // call initializer method to set pointers in the class
    Family.init();
    // Spawn Fawns in Linked List
    for (int i = 0; i <= num_of_generations; i++)
    {
        Fawn fawn;
        fawn.name = "Bambi";
        fawn.age = i;

        Family.birth_fawn(fawn, i);
    };
    // use display method to see all deer and their child relations
    Family.display();

    // use type definition fawn to instantiate new fawn.
    Fawn fawn;
    fawn.age = 10;
    fawn.name = "Ryan";

    // clear method completed wipes linked list
    Family.clear();

    std::cout << "---------" << std::endl;

    // remove fawn by reference number

    // number_of_fawns returns number of current fawns stored in family
    std::string fawnPopulation = "Fawn Population " + std::to_string(Family.number_of_fawns());

    std::cout << fawnPopulation << std::endl;

    return 0;
}