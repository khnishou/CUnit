# CUnit - Lightweight Unit Testing for C  

CUnit is a **simple and lightweight** unit testing framework for C. It provides:  

- **Test Cases & Suites** for structured testing  
- **Assertions** to compare expected vs. received values  
- **Automated Results Display** with detailed output  

### Usage Example  

```c
void my_test(void) {
    uint32_t count = 0;
    count += try("Example Test", set_int(42), set_int(42));
    results(count);
}
