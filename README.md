# OPPS_Project
Getting hands dirty on OOPS concepts and backend in C++.


## Follow the steps to include the mysql header and connect to mysql server.

```
  1. Go to https://www.dropbox.com/s/40h26grtqsggwrg/mysqlheaders.rar?dl=0&file_subpath=%2Fmysqlheaders and download 
      the header file.
      Download libmysql.a from https://www.dropbox.com/s/xj3it1pkhu2wb3h/libmysql.a.zip?dl=0
      Download libmysql.dll from https://www.dropbox.com/s/nktlkafhmez7c1o/libmysql.dll.zip?dl=0
      Note: - You have to unzip the downloaded files to get above mention files.
  2. Now go to C:\Program Files (x86)\CodeBlocks\MinGW\include  and paste all the header files here (not libmysql.a and libmysql.dll ).
  3  Go to C:\Program Files (x86)\CodeBlocks\MinGW\lib  and paste libmysql.a file here.
  4. Now go to codeblocks --> file -->new -->project -->console application -->go --> and fill all the required fields.
  5. Now go to your project folder --> bin --> debug --> add libmysql.dll here.
  6. Copy all the codes of projec and paste it in main.cpp of your project folder.
     Now go to the setting tab of codeblocks --> compiler --> linker setting --> add --> 
     C:\Program Files (x86)\CodeBlocks\MinGW\lib\libmysql.a
     Now go to codeblocks --> setting -->compiler --> search directories --> add -->
     C:\Program Files (x86)\CodeBlocks\MinGW\include
  7. Download XAMPP software and install it.
  8. Now run the xampp control panel as a administrator and start the apache server first and then mysql server.
  9. After starting go click adming button right after start button infront of mysql.
  10. Now your default browser will be open and you can see the database there. i.e localhost/phpmyadmin/
  11. Now you are good to go.
  
  ```
  
  
