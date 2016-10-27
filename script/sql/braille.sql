CREATE TABLE book_marks (
    id BIGINT PRIMARY KEY, 
    bookpath TEXT, 
    mark_pos INTEGER DEFAULT 0, -- 书签跳转位置
    descri CHARACTER(20), -- 书签描述信息
    create_time TIMESTAMP -- 创建时间
);

create table glob_id (
    id INTEGER PRIMARY KEY DEFAULT 1, -- 生成器类型
    cur_id BIGINT DEFAULT 1
);
