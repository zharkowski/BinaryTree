#include "complex_unit_3.hpp"

/*
 UNIT 3: Тестирование операций сравнения
 
 Список тестов:
 Тест 1: Сравнение двух совпадающих комплексных (для == и !=)
 Тест 2: Сравнение двух несовпадающих комплексных (для == и !=)
 Тест 3: Сравнение совпадающих комплексного и вещественного (для == и !=)
 Тест 4: Сравнение несовпадающих комплексного и вещественного (для == и !=)
 */

void run_complex_unit_3(){
    cout<<"[COMPLEX CLASS TESTING] UNIT 3 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com1 = Complex(3, 4);
        Complex com2 = Complex(3, 4);
        
        bool test1_ok = (com1 == com2);
        bool test2_ok = (com1 != com2);
        
        if (test1_ok && !test2_ok){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com1 = Complex(3, 4);
        Complex com2 = Complex(5, -4);
        
        bool test1_ok = (com1 == com2);
        bool test2_ok = (com1 != com2);
        
        if (!test1_ok && test2_ok){
            test_ok = true;
        }
        
        test_result(test_ok);
    }

    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com = Complex(3, 0);
        double db = 3;
        
        bool test1_ok = (com == db);
        bool test2_ok = (com != db);
        
        if (test1_ok && !test2_ok){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com = Complex(3, 7);
        double db = 3;
        
        bool test1_ok = (com == db);
        bool test2_ok = (com != db);
                
        if (!test1_ok && test2_ok){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 4 && test_ok == true) {
        cout<<"\n[TESTING] Unit 3 testing SUCCESSEDED.\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 3 testing FAILED on TEST #"<<test_id<<".\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    }
}

