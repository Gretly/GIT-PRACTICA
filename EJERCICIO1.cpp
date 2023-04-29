#include<iostream>
using namespace std;
 
int main(){

    cout<<"********** REALIZAR EL PRESUPUESTO IESTP ACORA **********"<<endl;

    int metros_opcion1{0};

    cout<<"CUANTOS METROS NECESITA EN CAT - 5: ";
    cin>>metros_opcion1;

    int metros_opcion2{0};

    cout<<"CUANTOS METROS NECESITA EN CAT - 6: ";
    cin>>metros_opcion2;

    const double precio_opcion1{3.5};
    const double precio_opcion2{4.8};
    const double igv{0.18};
    const int vigencia{45};

    cout<<"\nPRESUPUESTO DE CABLEADO"<<endl;

    cout<<"\nCANTIDAD DE METROS EN CAT - 5: " <<metros_opcion1<<endl;
    cout<<"CANTIDAD DE METROS EN CAT - 6: " <<metros_opcion2<<endl;
    cout<<"PRECIO POR METRO CAT - 5: " <<precio_opcion1<<endl;
    cout<<"PRECIO POR METRO CAT - 6: " <<precio_opcion2<<endl;
    //cout<<"PRECIO: ";

    //cout<<(metros_opcion1*precio_opcion1)+(metros_opcion2*precio_opcion2)<<"  SOLES." <<endl;
    //cout<<"IGV: "<<((metros_opcion1*precio_opcion1)+(metros_opcion2*precio_opcion2))*igv<< "  SOLES." <<endl;
    cout<<"PRECIO PARCIAL CAT - 5: ";
    cout<<(metros_opcion1*precio_opcion1)<<"  SOLES." <<endl;
    cout<<"PRECIO PARCIAL CAT - 6: ";
    cout<<(metros_opcion2*precio_opcion2)<<"  SOLES." <<endl;

    cout<<"IGV CAT - 5: "<<(metros_opcion1*precio_opcion1)*igv<< "  SOLES." <<endl;
    cout<<"IGV CAT - 6: "<<(metros_opcion2*precio_opcion2)*igv<< "  SOLES." <<endl;

    cout<<"***********************************" <<endl;

    /*cout<<"PRECIO TOTAL: ";
    cout<<(metros_opcion1*precio_opcion1)+(metros_opcion2*precio_opcion2)+
    (((metros_opcion1*precio_opcion1)+(metros_opcion2*precio_opcion2))*igv) <<"SOLES." <<endl;
    */
    cout<<"PRECIO TOTAL EN CAT - 5: ";
    cout<<(metros_opcion1*precio_opcion1)+((metros_opcion1*precio_opcion1)*igv) <<" SOLES." <<endl;

    cout<<"PRECIO TOTAL EN CAT - 6: ";
    cout<<(metros_opcion2*precio_opcion2)+(((metros_opcion2*precio_opcion2))*igv) <<" SOLES." <<endl;
    
    cout<<"ESTE PRESUPUESTO TIENE UNA VIGENCIA DE: " <<vigencia<<" DIAS.";

}