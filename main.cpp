#include "header.hpp"

int main(int, char**) {
    std::cout << "Hello, Dynamic Memory!\n";
    int *pi =new int(1023);
    std::vector<int>  *loc = new std::vector<int> {1,2,3,4,1,1,12,3};
    std::cout<<"Memory handling \t: [" << *pi << "]"<<std::endl;
    std::cout<<"Show member \t:[ " << loc->front() <<"]" <<std::endl;
    std::cout<<"Dynamically initalized const object" <<std::endl;
    const int *pi1= new const int(87);
    const std::string *pi2= new const std::string("michael");
    std::cout<<"Throw an exception if bad allocated memory " <<std::endl;
    int *bad = new (std::nothrow) int; //if allocation fail , new return a numm pointer 
    delete bad;
    std::cout<<"Frees the memory"  <<std::endl;
    int *nullPoint = nullptr;
    delete nullPoint;
    std::cout<<"Freed const object" <<std::endl;
    const int *constOb = new const int(123);
    delete constOb;

    std::cout<<"Explore"<<std::endl;
    int *notSmart = new int(12);
    int *notSmart2 = new int(12);
    auto nosmart3 = notSmart2;
    std::cout<<"1.Prove not smart \t:[ "<< nosmart3 <<"]" <<std::endl;
    std::cout<<"2.Prove not smart \t:[ "<< notSmart2 <<"]" <<std::endl;
    delete notSmart2;
    //std::cout<<"2.Prove not smart \t:[ "<< notSmart2 <<"]" <<std::endl;

    std::cout<<"Using smart Pointer" <<std::endl;
    std::shared_ptr<int> aOr = std::make_shared<int> (12);
    std::shared_ptr<int> aDes = std::make_shared<int> (12);
    auto cTest = aDes;
    std::cout<<"1.Variable ades \t:[" << aDes <<"]" <<std::endl;
    std::cout<<"2.Variable ades \t:[" << cTest <<"]" <<std::endl;
    auto dTest = std::make_shared<int> (120);
    std::cout<<"2.Variable ades \t:[" << aDes <<"]" <<std::endl;
    std::cout<<"2.Variable ades \t:[" << dTest <<"]" <<std::endl;
    auto nextTest = aDes;
    std::cout<<"3.Variable nextTest \t:[" << nextTest <<"]" <<std::endl;
    aDes =aOr;
    std::cout<<"4.Variable ades \t:[" << aDes <<"]" <<std::endl;
    std::cout<<"Using Shared Ptr with new" <<std::endl;
    std::shared_ptr<double> p1;
    std::shared_ptr<int> pTest (new int(42));
    
    std::cout<<"Other shared_ptr opeartion" << std::endl;
    std::shared_ptr<std::vector<int>> pointVec = std::make_shared<std::vector<int>>  (12,12);
    std::cout<<"Before reset \t:[" ;
    auto pointI= pointVec->cbegin();
    auto pointE= pointVec->cend();
    for(auto i = pointI ; i!=pointE;++i){
        std::cout<<  *i <<"|";
    }
    std::cout<<"]" <<std::endl;
    pointVec.reset(new std::vector<int>(12,0));
    std::cout<<"After  reset \t:[";
    for(auto i = pointI ; i!=pointE;++i){
        std::cout<<  *i <<"|";
    }
    std::cout<<"]" <<std::endl;

    std::shared_ptr<int>  shared = std::make_shared<int> (12);
    std::cout<<" Before reset \t:[" <<  shared <<"value \t: " << *shared  << "]" <<std::endl;
    shared.reset(new int(98));
    std::cout<<" after reset \t:[" <<  shared   <<" value \t: " << *shared<< "]" <<std::endl;


}
