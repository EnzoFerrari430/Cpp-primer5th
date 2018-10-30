/*
13.41：在push_back中，我们调用construct中为什么要使用后置递增（中文版中为前置递增，错误），如果使用前置递增会怎么样（中文版为后置递增，错误）

    a           b           c           d           e           f             g      .            ...........
    elements                                                                         first_free             cap

    使用后置，加入h的时候

        a           b           c           d           e           f             g       h     .                  ...........
    elements                                                                                    first_free                  cap

    first_free指向了最后一个元素的下一个位置


    如果使用前置递增，在加入h的时候回变成这个样子

    a           b           c           d           e           f             g      .       h            ...........
    elements                                                                                 first_free             cap

    fist_free前面有了一个空闲空间，而且first_free指向了最后一个元素的位置

*/
