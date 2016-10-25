#!/usr/bin/env python                                                                                                                                                                                                                   
# -*- coding: utf-8 -*-

#def FromNLToBraille(filePath):
def FromNLToBraille():
    filePath = "/Users/terencewei/gitsrc/python-pinyin/file"
    print "filePath = ", filePath
    file_object = open(filePath, 'rb')
    try:
        all_the_text = file_object.read().decode('utf-8')
        print "all_the_text=",  all_the_text
    finally:
        file_object.close()

    #TODO

if __name__ == "__main__":
    FromNLToBraille("/Users/terencewei/gitsrc/python-pinyin/file")
    print "dfkj  dlfjd lkdjf   sldfj".split(" ")
