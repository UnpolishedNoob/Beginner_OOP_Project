//Code by Pritom Banik - 2107052
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class customer_order;
class product{
    string p_name;
    float p_price;

    int p_sl;
    public:
    product(){p_sl=0;p_name="Unable!!";p_price=0;}
    product(string name,float price,int sl){  
        //constructor ,taking inputs
        p_name=name;
        p_price=price;
        p_sl=sl;
    }
    void show_product();
    string send_for_record(){
        return p_name;
    }
    float send_price(){
        return p_price;
    }

};
void product::show_product(){       
    //to show the product to owner
        cout<<p_sl<<". Name  : "<<setw(15)<<p_name;
        cout<<setw(15)<<"Price     : "<<setw(15)<<p_price<<endl;

}


class type{
    string type_name;
    class product brand[3];
    int type_sl;

    public:

    type(){
        type_sl=0;
    }
    void put_brand(int sl);
    void show_brand();
    void show_type_customer();
    //for showing the types only
    string return_name(int m){string a=brand[m].send_for_record();return a;};
    //for returning name for customer
    float return_price(int m){float a=brand[m].send_price();return a;};
    //for returning price for customer
};




void type::put_brand(int sl){ 
     //for taking product input
        type_sl=sl;             
        //taking type serial
        cout<<endl<<"Give pruduct type : ";
        cin>>type_name;
        cout<<endl<<"------Give info of "<<type_name<<" -----"<<endl<<endl;
        string nam;
        float pc;
        for(int i=0;i<3;i++){
            cout<<"Put name of product : ";
            cin>>nam;
            cout<<"price               : ";
            cin>>pc;
            cout<<endl;
            brand[i]=product(nam,pc,/*am,*/i+1); 
            //calling product constructor
}
}

void type::show_brand(){     
    //show the type name and 3 product of each type
    cout<<endl<<"       Product type : "<<type_sl+1<<". "<<type_name<<endl<<endl;
    for(int i=0;i<3;i++){
        brand[i].show_product();
    }
}

void type::show_type_customer(){  
    //show only types to customers
    cout<<type_sl+1<<". "<<type_name<<endl;
}




class customer_order{ 
    //for storing customer ordered product and show the class

    public:
    string product_name;
    int quantity;
    float price;
    customer_order(){
        product_name="No Product!!";
        quantity=0;
    }
    customer_order(string product_name,float price,int quantity){
        this->product_name=product_name;
        this->price=price;
        this->quantity=quantity;
    }
    float show_bill(){
        //for showing bill
        cout<<setw(20)<<setiosflags(ios::left)<<
        product_name<<setw(15)<<quantity<<setw(15)<<price*quantity<<endl<<endl;
      return (price*quantity);
    }

};



class manage{ 
    //this class manage the whole programm
    class type type_arr[100];
    int max,track,customer_max;
    class customer_order order[100];
    public:
    manage(){max=0;track=0;customer_max=0;}
    void put_type();
    void show_type();
    //For owner to show stored item
    void show_customer();
    //TO show the type to the customer
    void show_selled_product();
    
};


void manage::put_type(){
    if(max<100){
                int t=1;
                while(t--){
                type_arr[max].put_brand(max);
                max++;
                cout<<"Do you want to store more product? "<<endl
                <<"Press 1 for store more / Press 0 for end : ";
                cin>>t;
                if(t==0){
                    cout<<endl
                    <<"_____All of your product ready for sold _____"<<endl<<endl;
                }

                }
            }else{
                cout<<"Storage is full"<<endl;
            }
}

void manage::show_type(){ 
    //for owner to show the stored item
    cout<<endl<<"LIST OF STORED PRODUCT :"<<endl<<endl;
        for(int i=0;i<max;i++){
                type_arr[i].show_brand();
        }
}

void manage::show_customer(){
    //for customer to show types
 int t=1;
 while(t){
    if(max==0){cout<<endl
    <<"\tUnable!!\n      NO PRODUCT STORED"<<endl;break;}
    cout<<endl<<"The product we have : "<<endl;
    for(int i=0;i<max;i++){
        type_arr[i].show_type_customer();
    }
    cout<<"Give the product number you want to buy : ";
    cin>>track;
    track=track-1;
    if(track>max&&track>0){
        cout<<"Wrong input!!"<<endl;
    }else{
        type_arr[track].show_brand();
        cout<<"Give the serial number of item you want to buy : ";
        //here customer will give input to buy
    int m=0,q=0;
    cin>>m;
    m=m-1;
    cout<<"Give the quantity : ";
    cin>>q;
    string buy_name=type_arr[track].return_name(m);
    float buy_price=type_arr[track].return_price(m);
    order[customer_max]=customer_order(buy_name,buy_price,q);customer_max++;
    }
    if(customer_max>=100)
    {cout<<"You can't buy product for this time"<<endl<<endl;break;}
    cout<<endl<<endl<<"Press 1 if you want to buy more else press 0 :";
    cin>>t;
 }
}

void manage::show_selled_product(){//it will create a bill
    float total=0;
    if(customer_max==0){cout<<endl
    <<"Opps!! you have not select anything! Let's start again."<<endl<<endl;}
    else{
    cout<<endl<<"-------------The product you choose----------- "<<endl<<endl;
    cout<<setw(20)<<setiosflags(ios::left)<<"Product Name"<<setw(15)
    <<"Quantity"<<setw(15)<<"totalcost"<<endl<<endl;
    for(int x=0;x<customer_max;x++){
        total+=order[x].show_bill();
    }

    cout<<endl<<"Your total bill : "<<total<<endl;
    }
    customer_max=0;
}



int main(){
    manage obj;
    string take_pass,pass="admin";
    int i,t=1;
    while(t){
    cout<<"HI!! Enter as ->"<<endl
    <<endl<<"1.Owner "<<endl<<"2.Customer"<<endl<<"Choose one : ";
    cin>>i;
    if(i==1){

        cout<<"Give password to access  //(admin)// : ";
        cin>>take_pass;
        if(take_pass==pass){
            cout<<"Hello owner !! Have a good day ! "<<endl;
            obj.put_type();
            obj.show_type();
            t=1;
        }
        else{
            cout<<"Wrong Password!!"<<endl;
            t=1;

        }
    }
    else if(i==2){
        cout<<"HI Sir!! Have a good shopping !"<<endl;
        obj.show_customer();
        obj.show_selled_product();
        t=1;
    }
    else{
        cout<<"Wrong input !! "<<endl<<"---Try again--- "<<endl<<endl;
    }
    }


    return 0;
}
/*Pritom Banik_2107052*/