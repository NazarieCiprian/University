package com.example.ciprian.exam

import android.app.Application
import android.arch.persistence.room.Room
import com.example.ciprian.exam.db.MyDatabase
import com.example.ciprian.exam.domain.Message

class MyApp: Application(){
    lateinit var db:MyDatabase
    var publicList: MutableList<Message>?=null
    var userList: MutableList<String>? = null
    var receiverList:MutableList<Message>?=null
    var senderList:MutableList<Message>?= null
    override fun onCreate() {
        super.onCreate()
        db = Room.databaseBuilder<MyDatabase>(applicationContext,
                MyDatabase::class.java, "database-name1").build()
    }
}