package com.example.ciprian.exam.domain

import android.arch.persistence.room.Entity
import android.arch.persistence.room.PrimaryKey
import java.io.Serializable

@Entity(tableName="messages")
data class Message(@field:PrimaryKey(autoGenerate = true)
            var id:Int,var sender:String?, var receiver:String?, var text:String?, var date:Int?,var type:String?):Serializable{

}