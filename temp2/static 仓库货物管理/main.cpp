#include <iostream>

using namespace std;

//货物类
class Goods
{
public:
    Goods()
    {
        next = NULL;
        weight = 0;
        cout << "创建了一个重量是" << weight << "货物" << endl;
        total_weight += weight;
    }


    Goods(int w)
    {
        next = NULL;
        weight = w;
        cout << "有参构造函数 --- 创建了一个重量是 " << weight << "货物" << endl;
        total_weight += weight;
    }


    int getWeight()
    {
        return weight;
    }

    Goods(const Goods &another)
    {
        next = NULL;
        weight = another.weight;
        cout << "有参构造函数 --- 创建了一个重量是 " << weight << "货物" << endl;
        total_weight += weight;
    }

    void operator= (const Goods &anoth)
    {
        next = NULL;
        weight = anoth.weight;
        cout << "有参构造函数 --- 创建了一个重量是 " << weight << "货物" << endl;
        total_weight = anoth.total_weight;
    }

    ~Goods()
    {
        cout << "删除了一个重量是 " << weight << "货物" << endl;
    }

    Goods* next;


private:
    int weight;//每个货物的重量
    static int total_weight;//仓库总重量
};

int Goods::total_weight = 0;

void printLink(Goods * &head)
{
    for (int i = 0; head != nullptr; head = head->next,i++)
    {
        cout << "i = " << i << endl;
        cout << "head.weight -- " << head->getWeight() << endl;
    }

}


void buy(Goods ** go , int weight)
{
    Goods *temp = *go;

    Goods *g1 = new Goods(weight);

    if (temp == NULL)
    {
        temp = g1;
        *go = temp;

    }
    else
    {

        g1->next = temp;
        *go = g1;
    }


    printLink(*go);
}

void sale(Goods ** go)
{

    Goods *temp = *go;
    Goods *temp2 = nullptr;

    if (temp->next != NULL)
    {
        temp2 = temp->next;
        if (temp != nullptr)
        {
            delete temp;
        }

        *go = temp2;
    }


}



int main(void)
{

    int choice = 0;

    Goods g1 = Goods(3);

    Goods*head = NULL;//整个仓库的货物的一个头指针
    int w;

    do {
        cout << "1 进货" << endl;
        cout << "2 出货" << endl;
        cout << "3 exit" << endl;
        cin >> choice;


        switch (choice)
        {
            case 1:
            {
                //进货
                cout << "请输入新的货物重量" << endl;
                cin >> w;

                buy(&head, w);
            }
            break;
            case 2:
            {
                //出货
                sale(&head);
                printLink(head);
            }
            case 3:
                return 0;
                break;
            default:
                break;
        }
        
        
        cout << "当前仓库目前的总重量是" << endl;


    } while (1);
    
    
    
    return 0;
}