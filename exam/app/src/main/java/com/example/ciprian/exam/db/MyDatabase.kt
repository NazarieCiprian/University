package com.example.ciprian.exam.db

import android.arch.persistence.room.Database
import android.arch.persistence.room.RoomDatabase
import com.example.ciprian.exam.domain.Message

@Database(entities = [Message::class], version = 1)
abstract class MyDatabase: RoomDatabase(){
    abstract val messageDao:MessageDao
}