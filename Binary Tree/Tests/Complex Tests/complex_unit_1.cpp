#include "complex_unit_1.hpp"

/*
 UNIT 1: Тестирование создания комплексного числа
 
 Список тестов:
 Тест 1: Cоздание комплексного числа с нулевой действительной частью и нулевой мнимой частью
 Тест 2: Cоздание комплексного числа с ненулевой действительной частью и нулевой мнимой частью
 Тест 2: Cоздание комплексного числа с ненулевой действительной частью и ненулевой мнимой частью
 */

void run_complex_unit_1(){
    cout<<"[COMPLEX CLASS TESTING] UNIT 1 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com = Complex();
        
        
        if (com.return_re() == 0 && com.return_im() == 0){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com = Complex(5);
        
        
        if (com.return_re() == 5 && com.return_im() == 0){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com = Complex(5, -2);
        
        
        if (com.return_re() == 5 && com.return_im() == -2){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 1 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 1 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}

