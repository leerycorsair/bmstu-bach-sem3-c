from tkinter import *

from tkinter import messagebox as mb
import ctypes

lib = ctypes.CDLL('C:\msys64\home\Vlad/iu7-cprog-labs-2020-leonovvladislav\lab_12_02_02\dlarr.dll')
arr_fill_fib = lib.arr_fill_fib
arr_fill_fib.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
arr_fill_fib.restype = ctypes.c_int
duples_del = lib.del_duples
duples_del.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,ctypes.POINTER(ctypes.c_int), ctypes.c_int)
duples_del.restype = ctypes.c_int

def cr_info():
    info ='''Создателем данной программы является\nстудент МГТУ им. Н.Э. Баумана группы ИУ7-36Б\n\
Леонов Владислав Вячеславович'''
    mb.showinfo(title = 'О создателе', message = info)

def fib_arr_create():
    global arr_size_entry, data_fib, res_text, arr_fill_fib
    data_fib  = arr_size_entry.get()
    try:
        data_fib = (int(data_fib))
        arr = (ctypes.c_int*data_fib)()
        res = arr_fill_fib(arr, data_fib)
        if (res):
            mb.showerror(title='Ошибка', message='Переполнение типа. Максимальный порядковый номер числа Фиббоначи - 47')
            return
        arr = list(arr)
        res_text.delete('1.0', END)
        for i in range(len(arr)):
            res_text.insert('end', '{0:>10d}'.format(arr[i]) + ' ' + '\n'*(i % 5//4))
    except:
        mb.showerror(title='Ошибка', message='Некорректный ввод.')
        data_fib = ''

def del_duples():
    global input_text, output_text, duples_del
    src = input_text.get('1.0', END)
    if src == '' or len(src.split()) <= 1:
        mb.showerror(title = 'Ошибка', message = 'Вы не ввели массив.')
    try:
        src = [int(src.split()[i]) for i in range(len(src.split()))]
        src = (ctypes.c_int * len(src))(*src)
        dst = (ctypes.c_int*0)()
        e_c = duples_del(src, len(src), dst, 0)
        dst = (ctypes.c_int*e_c)()
        duples_del(src, len(src), dst, e_c)
        dst = list(dst)
        output_text.delete('1.0', END)
        for i in range(len(dst)):
            output_text.insert('end', '{0:>10d}'.format(dst[i]) + ' ' + '\n'*(i % 5//4))
    except:
        mb.showerror(title='Ошибка', message='Некорректный ввод.')

win = Tk()
win.title('Работа с динамическими библиотеками')
win.configure(background = '#3caa3c')
win.geometry('1350x650+10+10')

lf = Frame(win,background = '#3caa3c')
lf.grid(row = 0, column = 0)
rf = Frame(win,background = '#3caa3c')
rf.grid(row = 0, column = 1)

# Массив чисел Фиббоначи
fib_frame = LabelFrame(lf, text = 'Создание массива чисел Фиббоначи', font = ('Times New Roman Bold',14),\
padx = 10, pady = 30,background = '#3caa3c',fg = '#ffffff')

fib_frame_top = Frame(fib_frame, padx = 10, pady = 10,background = '#3caa3c')
fib_frame_top.grid(column = 0, row = 0)
arr_size_entry = Entry(fib_frame_top, font = ('Times New Roman Bold',14), width = 30,background = '#00a550', fg = '#ffffff')
arr_size_entry.grid(column = 0, row = 0)
arr_size_entry.insert(0, 'Введите размер...')
gen_button = Button(fib_frame_top, text = 'Создать',font = ('Times New Roman Bold',14),\
command = lambda: fib_arr_create(),background = '#00a550', fg = '#ffffff')
gen_button.grid(row = 0, column = 1, padx = 10, pady = 10)

fib_frame_bot = Frame(fib_frame, padx = 10, pady = 10, background = '#3caa3c')
fib_frame_bot.grid(column = 0, row = 1)
res_text = Text(fib_frame_bot,font = ('Times New Roman Bold',14),  width = 55, height = 10, bg = '#00a550', fg = '#ffffff', )
res_text.grid(column = 0, row = 0)
fib_scroll = Scrollbar(fib_frame_bot, command=res_text.yview)
fib_scroll.grid(column = 1, row = 0, sticky = "ns")
res_text.config(yscrollcommand=fib_scroll.set)
fib_frame.grid(column = 0, row = 0, pady = 5, padx=5)

author_but = Button(lf, text = 'Об авторе',font = ('Times New Roman Bold',14),\
command = lambda: cr_info(),background = '#00a550', fg = '#ffffff')
author_but.grid(row = 1, column = 0, padx = 30, pady = 30)

# Удаление вхождений элементов
del_duples_frame = LabelFrame(rf, text = 'Удаление дупликатов из массива', font = ('Times New Roman Bold',14),\
padx = 10, pady = 30,background = '#3caa3c',fg = '#ffffff')
del_duples_frame.grid(column = 0, row = 0, pady = 5, padx=5)

dd_top = Frame(del_duples_frame, padx = 10, pady = 10, background = '#3caa3c')
dd_top.grid(column = 0, row = 0)
input_text = Text(dd_top,font = ('Times New Roman Bold',14),  width = 55, height = 10, bg = '#00a550', fg = '#ffffff', )
input_text.grid(column = 0, row = 0)
input_text.insert(1.0, 'Введите целочисленный массив...')
in_scroll = Scrollbar(dd_top, command=input_text.yview)
in_scroll.grid(column = 1, row = 0, sticky = "ns")
input_text.config(yscrollcommand=in_scroll.set)
dd_button = Button(dd_top, text = '⬇ Удалить ⬇',font = ('Times New Roman Bold',14),\
command = lambda: del_duples(),background = '#00a550', fg = '#ffffff')
dd_button.grid( row = 1, column = 0, padx = 5, pady = 10)

dd_bot = Frame(del_duples_frame, padx = 10, pady = 10, background = '#3caa3c')
dd_bot.grid(column = 0, row = 1)
output_text = Text(dd_bot,font = ('Times New Roman Bold',14),  width = 55, height = 10, bg = '#00a550', fg = '#ffffff', )
output_text.grid(column = 0, row = 0)
out_scroll = Scrollbar(dd_bot, command=output_text.yview)
out_scroll.grid(column = 1, row = 0, sticky = "ns")
input_text.config(yscrollcommand=out_scroll.set)

data_fib = ''
data_duples = ''

win.mainloop()