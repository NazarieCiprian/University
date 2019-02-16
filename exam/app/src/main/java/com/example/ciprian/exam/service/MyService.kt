package com.example.ciprian.exam.service

import com.example.ciprian.exam.domain.Message
import retrofit2.Response
import retrofit2.http.*
import rx.Observable

interface MyService {


    @get:GET("public")
    val public:Observable<List<Message>>

    @get:GET("users")
    val users:Observable<List<String>>

    @GET("sender/{name}")
    fun getSender(@Path("name") name:String): Observable<List<Message>>

    @GET("receiver/{name}")
    fun getReceiver(@Path("name") name:String): Observable<List<Message>>

    @POST("message")
    fun addMessage(@Body message: Message):Observable<Message>

    @GET("private/{user}")
    fun getPrivate(@Path("user")user:String): Observable<List<Message>>

    @DELETE("message/{id}")
    fun deleteMessage(@Path("id")id:Int):Observable<Response<Any>>
    
    companion object {
        const val SERVICE_ENDPOINT = "https://d3ed6edf.ngrok.io"
    }
}