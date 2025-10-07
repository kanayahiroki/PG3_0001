#include <iostream>
#include <list>
using namespace std;


int main() {
    // 1970年の山手線駅
    list<const char*> lst{
    "Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani","Nippori","Tabata","Komagome",
    "Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
    "Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
    };

    printf("1970\n");
    for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
        cout << *itr;
        auto next = itr;
        ++next;
        if (next != lst.end())
            cout << " - ";



    }
    printf("\n\n");

	printf("2019\n");
    


	for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        if (*itr == "Tabata")
        {
            itr = lst.insert(itr, "Nisi-Nippori");
            ++itr;
        }
		
	}   


     for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
         cout << *itr;
         auto next = itr;
         ++next;
         if (next != lst.end())
             cout << " - ";
    }


     printf("\n\n");

     printf("2022\n");
     for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
         if (*itr == "Tamachi")
         {
             itr = lst.insert(itr, "Takanawa Gateway");
             ++itr;
         }

     }


     for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
         cout << *itr;
         auto next = itr;
         ++next;
         if (next != lst.end())
             cout << " - ";

     }
     printf("\n\n");
    return 0;
}
