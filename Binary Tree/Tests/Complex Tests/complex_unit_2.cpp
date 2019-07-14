#include "complex_unit_2.hpp"

/*
 UNIT 2: Тестирование математических операций с классом Complex
 
 Список тестов:
 Тест 1: Сложение комплексного и комплексного (операции + и +=)
 Тест 2: Сложение комплексного и вещественного (операции + и +=)
 Тест 3: Произведение комплексного и вещественного (операции * и *=)
 Тест 4: Произведение комплексного и комплексного
 */

void run_complex_unit_2(){
    cout<<"[COMPLEX CLASS TESTING] UNIT 2 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com1 = Complex(2, 5);
        Complex com2 = Complex(3, 4);
        
        Complex test_com_1 = com1 + com2;
        Complex test_com_2 = com1;
        test_com_2 += com2;
        
        if (test_com_1.return_re() == 5 && test_com_1.return_im() == 9 && test_com_2.return_re() == 5 && test_com_2.return_im() == 9){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
            
        Complex com1 = Complex(2, 5);
        double db = 5;
            
        Complex test_com_1 = com1 + db;
        Complex test_com_2 = com1;
        test_com_2 += db;
        
        if (test_com_1.return_re() == 7 && test_com_1.return_im() == 5 && test_com_2.return_re() == 7 && test_com_2.return_im() == 5){
            test_ok = true;
        }
            
        test_result(test_ok);
    }

    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com1 = Complex(2, 5);
        double db = 5;
        
        Complex test_com_1 = com1 * db;
        Complex test_com_2 = com1;
        test_com_2 *= db;          
        
        if (test_com_1.return_re() == 10 && test_com_1.return_im() == 25 && test_com_2.return_re() == 10 && test_com_2.return_im() == 25){
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Complex com1 = Complex(2, 5);
        Complex com2 = Complex(3, 4);
        
        Complex test_com = com1 * com2;
        
        if (test_com == Complex(-14, 23)){
            test_ok = true;
        }
        
        test_result(test_ok);
    }

    if (test_id == 4 && test_ok == true) {
        cout<<"\n[TESTING] Unit 2 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 2 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}

