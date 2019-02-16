package com.example.ciprian.exam.db

import android.arch.lifecycle.LiveData
import android.arch.persistence.room.Dao
import android.arch.persistence.room.Delete
import android.arch.persistence.room.Insert
import android.arch.persistence.room.Query
import com.example.ciprian.exam.domain.Message


@Dao
interface MessageDao{

    @get:Query("select * from messages order by date desc")
    val bookmarks: LiveData<List<Message>>

    @Query("delete from messages")
    fun deleteMessages()

    @Delete
    fun deleteMessage(message: Message)
    @Insert
    fun addMessages(messages:List<Message>)
}