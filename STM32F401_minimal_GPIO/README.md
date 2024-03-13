# Overview

Sehubungan dengan rumitnya device header files yang ujung ujungnya berakhir dengan Error karena beberapa file mungkin salah versi, tidak lengkap; maka disarikan yang perlu saja.
Typedef structure sengaja tidak digunakan karena efeknya melebar menyangkut struktur yang belum dikuasai dan tidak diperlukan dalam scope saat ini.

Proyek kali ini menggunakan board Blackpill versi 3 yang sudah dilengkapi tombol tambahan KEY di port A pin 0, dan LED standar di port C pin 13.



# Uploading and Debugging


1. Plug STLink V2 ke laptop dan kabel SWD ke Blackpill.

2. Kita perlu dua window terminal. Pertama untuk menjalankan st-util yang akan stand-by dan listen ke port 4242 sebagai pemroses remote. Window ini menampilkan informasi keping MCU pada Blackpill, dan informasi umum debugger.

3. Pada terminal kedua, jalankan `gdb-multiarch main.elf` 

4. Arahkan proses gdb ke st-util pada port default, dengan perintah `target extended-remote :4242`

5. Perintahkan `load` pada window gdb dan informasi proses langsung dilaporkan pada window st-util.

6. Kode kita sudah dimuat ke flash. Ketik `continue` agar program berlari beberapa saat lalu tekan `ctrl+C` untuk pause.

Setelah itu Anda dapat menggunakan beberapa perintah GDB untuk melihat jalannya program. Misalnya step, info register (asembli), print variabel, mundu, dll. `s`/`si`/`n`/`ni`

Screen copy

// window st-util /////////////////////////


2024-03-13T14:42:21 INFO common.c: F4xx (Dynamic Efficency): 96 KiB SRAM, 384 KiB flash in at least 16 KiB pages.   
2024-03-13T14:42:21 INFO gdb-server.c: flash_erase: block 08000000 -> 4000   
2024-03-13T14:42:21 INFO gdb-server.c: flash_erase: page 08000000   
EraseFlash - Sector:0x0 Size:0x4000 2024-03-13T14:42:21 INFO common.c: Starting Flash write for F2/F4/F7/L4    
2024-03-13T14:42:21 INFO flash_loader.c: Successfully loaded flash loader in sram    
2024-03-13T14:42:21 INFO flash_loader.c: Clear DFSR    
2024-03-13T14:42:21 INFO common.c: enabling 32-bit flash writes    
2024-03-13T14:42:21 INFO gdb-server.c: flash_do: block 08000000 -> 4000    
2024-03-13T14:42:21 INFO gdb-server.c: flash_do: page 08000000    
2024-03-13T14:58:26 ERROR gdb-server.c: cannot recv: -2    
2024-03-13T14:58:26 INFO gdb-server.c: Listening at :4242....    
    
    
// window GDB /////////////////////////

*(gdb) load*    
Loading section .vector_table, size 0xc4 lma 0x8000000    
Loading section .text, size 0xe8 lma 0x80000c4    
Start address 0x080000c4, load size 428    
Transfer rate: 601 bytes/sec, 214 bytes/write.    
*(gdb) s*    
Single stepping until exit from function reset_handler,
which has no line number information.    
Note: automatically using hardware breakpoints for read-only addresses.    
main () at src/main.c:15    
15	int main(void) {    
*(gdb) s*    
17	  RCC_AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN) ;    
*(gdb) s*    
26	  GPIOA_MODER |= 0b00;    
     
. . .    
*(gdb) s*    
30	  GPIOC_OTYPER |= 1U << 13;    
*(gdb) s*    
41	  GPIOA_PUPDR |= PUPDR_PULL_UP << KEY_btn_bit;    
*(gdb) s*    
44	  bool pressed = false;    
*(gdb) s*    
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
*(gdb) __p pressed__*    
$1 = false    
*(gdb) s*    
50	    if(keyEvt ){              
*(gdb) p keyEvt*    
$2 = 0    
*(gdb) s*     
57	      pressed = false;                
*(gdb) s*     
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
*(gdb) s*    
50	    if(keyEvt ){                             
*(gdb) p keyEvt*    
$3 = 1    
*(gdb) s*     
51	      if (!pressed)    
*(gdb) p pressed*    
$4 = false    
*(gdb) s*    
52	        GPIOC_ODR ^= (1 << LED_bit);      
*(gdb) s*     
54	      pressed = true;                           
*(gdb) s*    
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
*(gdb) s*    
50	    if(keyEvt ){                             
*(gdb) p keyEvt*    
$5 = 1    
*(gdb) s*     
51	      if (!pressed)    
*(gdb) s*     
54	      pressed = true;                           
*(gdb) s*     
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
*(gdb) s*    
50	    if(keyEvt ){                              
*(gdb) s*     
57	      pressed = false;                  
*(gdb) s*    
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);   
*(gdb) s*    
50	    if(keyEvt ){                              
*(gdb) s*    
51	      if (!pressed)    
*(gdb) s*     
52	        GPIOC_ODR ^= (1 << LED_bit);     
*(gdb) s*     
54	      pressed = true;                          
*(gdb) s*     
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
*(gdb) s*    
50	    if(keyEvt ){                             
*(gdb) s*     
57	      pressed = false;                   
*(gdb) s*     
48	    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit);     
_**(gdb) q**_    
    
Quit anyway? (y or n) y    
