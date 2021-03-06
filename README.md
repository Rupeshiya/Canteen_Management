<p align="center">
  <img  src="https://user-images.githubusercontent.com/31209617/48580549-8816a200-e945-11e8-8814-7e927f7d21d7.png" />
</p>

<p align="center"><b>CANTEEN MANAGEMENT SYSTEM</b></p>


#### FEATURES:

* Register.
* Login.
* Add Customers.
* Add Products.
* Customers and products search.
* Display Customer. 
* Display Product.
* Modify Customer Details.
* Modify Product Details.
* Delete Customer.
* Delete Product.
* Billing Option.
* Display Invoice. 

<p align="center"><b>Application Working ..</b></p>

<p align="center">
<img src="https://user-images.githubusercontent.com/31209617/48620324-b9cf4d80-e9c5-11e8-9caa-45e0bba493e8.gif" />
</p>  


###                                      MySql DATABASE AS BACKEND  

* The code for this is in mysql_code --> main.cpp

#### MySqL setup in codeblocks.

**Follow the steps to include the mysql header and connect to mysql server.**


*  Go to https://www.dropbox.com/s/40h26grtqsggwrg/mysqlheaders.rar?dl=0&file_subpath=%2Fmysqlheaders and download 
      the header file.
      Download libmysql.a from https://www.dropbox.com/s/xj3it1pkhu2wb3h/libmysql.a.zip?dl=0
      Download libmysql.dll from https://www.dropbox.com/s/nktlkafhmez7c1o/libmysql.dll.zip?dl=0
      Note: - You have to unzip the downloaded files to get above mention files.
*  Now go to C:\Program Files (x86)\CodeBlocks\MinGW\include  and paste all the header files here (not libmysql.a and libmysql.dll ).
*  Go to C:\Program Files (x86)\CodeBlocks\MinGW\lib  and paste libmysql.a file here.
*  Now go to codeblocks --> file -->new -->project -->console application -->go --> and fill all the required fields.
*  Now go to your project folder --> bin --> debug --> add libmysql.dll here.
*  Copy all the codes of projec and paste it in main.cpp of your project folder.
     Now go to the setting tab of codeblocks --> compiler --> linker setting --> add --> 
     C:\Program Files (x86)\CodeBlocks\MinGW\lib\libmysql.a
     Now go to codeblocks --> setting -->compiler --> search directories --> add -->
     C:\Program Files (x86)\CodeBlocks\MinGW\include
*  Download XAMPP software and install it.
* Now run the xampp control panel as a administrator and start the apache server first and then mysql server.
*  After starting go click adming button right after start button infront of mysql.
*  Now your default browser will be open and you can see the database there. i.e localhost/phpmyadmin/
*  Now you are good to go.
  
###                                       CSV FILE AS BACKEND  

* The code for this is in csv_code -->csvmain.cpp.

