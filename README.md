# transport_code


c++コンパイルメモ
g++ -I /usr/local/include test.cpp -o test

g++ -I /usr/local/include -L/usr/local/lib -lboost_system udp.cpp -o udp


cmake用意


-o コンパイルして、その結果を実行ファイルを生成
（指定しないとa.out)
https://qiita.com/seriru13/items/c2f5192615162c4c3f47
