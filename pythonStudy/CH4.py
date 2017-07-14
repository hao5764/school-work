使用列表
list =[100,23,45]
print list[0]
print list[1]
print list[2]
print len(list)

列表尾部的添加
hello = ['hi', 'hello']
world = ['earth', 'field', 'universe']
hello.append('nihao')
print hello 
hello.extend(world)
print hello

插入数据与元素定位
hello = ['hi', 'hello']
hello.insert(0,'nihao')
print hello
print hello.index('hi')

列表弹出与删除
hello = ['nihao', 'hi', 'hello']
hello.remove('nihao')
print hello
hello.pop(0)
print hello

字符串的切割与列表合成
manager = 'tuotatianwang,taibaijinxing,juanliandajiang'
manager_list=manager.split(',')
print manager_list
new_manager=' '.join(manager_list)
print new_manager

列表求和
gardens = [7204, 3640, 1200, 1240, 71800, 3200, 604]
total = 0
for num in gardens:
    total+=num
print total
print sum(gardens)

range 的使用
range(10) [0,1,2,3,4,5,6,7,8,9]
for num in range(100) 0-99
range(1,10) [1,2,3,4.5,6,7,8,9]
range(1,10,2) [1,3,5,7,9]
range(10,1,-2) [10,8,6,4,2]
xrange

while 循环
first = 0
second = 1
# Please write code here
while first<100 :
    print first
    first, second = second, first + second
print 'Everything is done'

简单斐波那契
n = int(raw_input())
first =0
second=1
while n>0:
    first,second=second,first+second
    n=n-1
print first
