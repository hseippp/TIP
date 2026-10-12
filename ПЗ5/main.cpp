//Способ 1
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;
//     while (A != B) {
//         if (A % 2 == 0 and A / 2 >= B) {
//             A /= 2;
//             cout<<":2"<<"\n";
//         } else {
//             A--;
//             cout<<"-1"<<"\n";
//         }
//     }
// }

//Способ 2
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;   
    
//     for (;;) {
//         if (A == B) break;
//         if (A % 2 == 0 and A / 2 >= B) {
//            A /= 2;
//            cout<<":2"<<"\n";
//         } 
//         else {
//             A--;
//             cout<<"-1"<<"\n";
//         }
//     }
// }

//Способ 3
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;
    
//     if (A != B) do {
//         if (A % 2 == 0 and A / 2 >= B) {
//             A /= 2;
//             cout<<":2"<<"\n";
//         } else {
//             A--;
//             cout<<"-1"<<"\n";
//         }
//     } while (A > B);
// }