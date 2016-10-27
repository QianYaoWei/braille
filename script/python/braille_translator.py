#!/usr/bin/env python                                                                                                                                                                                                                   
# -*- coding: utf-8 -*-

try:
    import pypinyin
    pinyin = pypinyin.pinyin
except ImportError:
    pinyin = None

def FromNLToBraille(filePath):
    return [2, 3, 5, 6, 4, 3, 6]
    #file_object = open(filePath, 'rb')
    #try:
    #    all_the_text = file_object.read().decode('utf-8')
    #finally:
    #    file_object.close()

    #if pinyin is None:
    #    print("no pypinyin module!")
    #else:
    #    print pinyin(all_the_text)

    return None

if __name__ == "__main__":
    FromNLToBraille("/Users/terencewei/gitsrc/python-pinyin/file")
