#include "ft_printf.h"
# include <stdio.h>
// int	main(void)
// {
//     ft_printf("%s" ,"Ero\n");
// }

// int main(void)
// {
//     int a = 'a';
//     write(1, &a, 1);
//     ft_printf("%c\n", 'a');

// }

// int main(void)
// {
//     ft_printf("%d\n", 'ssss');
//     printf("%d\n", 'ssss');
// }

// int main()
// {
//     ft_printf("%sena%d\n", 1137);
//     printf("%sena%d\n", 1137);
// }
// int main()
// {
// 	ft_printf("%p\n", (void *) -1);
//     printf("%p\n", (void *) -1);
// }
// int main()
// {
// 	// int x = 123;
// 	// int *y = &x;
// 	printf("%u\n", -123);
// 	ft_printf("%u\n", -123);
// }
// CHAR_BIT	Bit alanı olmayan en küçük değişkendeki bit sayısı.	8
// SCHAR_MIN	türünde signed charbir değişken için en düşük değer.	-128
// SCHAR_MAX	türünde signed charbir değişken için en büyük değer.	127
// UCHAR_MAX	türünde unsigned charbir değişken için en büyük değer.	255 (0xff)
// CHAR_MIN	türünde charbir değişken için en düşük değer.	-128; /J seçeneği kullanılıyorsa 0
// CHAR_MAX	türünde charbir değişken için en büyük değer.	127; /J seçeneği kullanılıyorsa 255
// MB_LEN_MAX	Çok karakterli sabitteki bayt sayısı üst sınırı.	5
// SHRT_MIN	türünde shortbir değişken için en düşük değer.	-32768
// SHRT_MAX	türünde shortbir değişken için en büyük değer.	32767
// USHRT_MAX	türünde unsigned shortbir değişken için en büyük değer.	65535 (0xffff)
// INT_MIN	türünde intbir değişken için en düşük değer.	-2147483647 - 1
// INT_MAX	türünde intbir değişken için en büyük değer.	2147483647
// UINT_MAX	türünde unsigned intbir değişken için en büyük değer.	4294967295 (0xffffffff)
// LONG_MIN	türünde longbir değişken için en düşük değer.	-2147483647 - 1
// LONG_MAX	türünde longbir değişken için en büyük değer.	2147483647
// ULONG_MAX	türünde unsigned longbir değişken için en büyük değer.	4294967295 (0xffffffff)
// LLONG_MIN	türünde long longbir değişken için en düşük değer.	-9,223,372,036,854,775,807 - 1
// LLONG_MAX	türünde long longbir değişken için en büyük değer.	9,223,372,036,854,775,807
// ULLONG_MAX	türünde unsigned long long bir değişken için en büyük değer.	18.446.744.073.709.551.615 (0xffffffffffffffff)
//NOTT!!!
// (void *) -1 == (size_t) -1
// It's 0xFFFFFFFF on 32 bit machine and 0xFFFFFFFFFFFFFFFF on 64 bit machine, an invalid address that is supposed to be bigger than any other address.
//(the highest possible address) (unsigned long long)