package com.example.ciprian.exam

import android.content.Context
import android.net.ConnectivityManager
import android.view.View
import android.widget.ProgressBar
import com.example.ciprian.exam.domain.Message
import com.example.ciprian.exam.service.MyService
import com.example.ciprian.exam.service.ServiceFactory
import com.example.ciprian.exam.utils.logd
import com.example.ciprian.exam.utils.loge
import retrofit2.Response
import rx.Subscriber
import rx.android.schedulers.AndroidSchedulers
import rx.schedulers.Schedulers
import kotlin.math.min

internal class Manager(val app: MyApp) {
    private val service: MyService = ServiceFactory
            .createRetrofitService(MyService::class.java, MyService.SERVICE_ENDPOINT)

    fun loadPublic(progressBar: ProgressBar, callback: MyCallback,activity: FirstActivity){
        service.public
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<List<Message>>(){
                    override fun onCompleted() {
                        logd("Completed getting public messages")
                        progressBar.visibility = View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while getting public messages")
                    }

                    override fun onNext(t: List<Message>?) {
                        Thread(Runnable {
                            var sorted = t!!.sortedWith(compareByDescending<Message>{it.date} ).subList(0, min(10,t!!.size))
                            app.publicList = sorted as MutableList<Message>
                            activity.runOnUiThread(object:Runnable{
                                override fun run() {
                                    activity.adapter!!.setData(app.publicList!!,progressBar,app,callback,activity)
                                }
                            })
                        }).start()
                    }
                })
    }

    fun loadUsers(progressBar: ProgressBar, callback: MyCallback,activity: ThirdActivity){
        service.users
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<List<String>>(){
                    override fun onCompleted() {
                        logd("Completed getting users")
                        progressBar.visibility = View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while getting public messages")
                    }

                    override fun onNext(t: List<String>?) {
                        Thread(Runnable {
                            var sorted = t!!.sorted()
                            app.userList = sorted as MutableList<String>
                            activity.runOnUiThread(object:Runnable{
                                override fun run() {
                                    activity.adapter!!.setData(app.userList!!,progressBar,app,callback,activity)
                                }
                            })
                        }).start()
                    }
                })
    }

    fun loadReceiver(name:String,progressBar: ProgressBar, callback: MyCallback,activity: FourthActivity){
        service.getReceiver(name)
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<List<Message>>(){
                    override fun onCompleted() {
                        logd("Completed getting receiver")
                        progressBar.visibility = View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while getting messages")
                    }

                    override fun onNext(t: List<Message>?) {
                        Thread(Runnable {
                            var sorted = t!!.sortedWith(compareByDescending<Message> { it.date })
                            app.receiverList = sorted as MutableList<Message>
                            activity.runOnUiThread(object:Runnable{
                                override fun run() {
                                    activity.adapter!!.setData(app.receiverList!!,progressBar,app,callback,activity)
                                }
                            })
                        }).start()
                    }
                })
    }

    fun loadSender(name:String,progressBar: ProgressBar, callback: MyCallback,activity: FifthActivity){
        service.getSender(name)
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<List<Message>>(){
                    override fun onCompleted() {
                        logd("Completed getting sender")
                        progressBar.visibility = View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while getting  messages")
                    }

                    override fun onNext(t: List<Message>?) {
                        Thread(Runnable {
                            var sorted = t!!.sortedWith(compareByDescending<Message> { it.date })
                            app.senderList = sorted as MutableList<Message>
                            activity.runOnUiThread(object:Runnable{
                                override fun run() {
                                    activity.adapter!!.setData(app.senderList!!,progressBar,app,callback,activity)
                                }
                            })
                        }).start()
                    }
                })
    }

    fun saveMessage(message: Message, progressBar: ProgressBar,callback: MyCallback,activity: NewActivity){
        service.addMessage(message)
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<Message>(){
                    override fun onCompleted() {
                        logd("Completed saving message")
                        progressBar.visibility =View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while saving")
                    }

                    override fun onNext(t: Message?) {
                        Thread(Runnable {
                            callback.clear()
                        }).start()
                    }
                })
    }

    fun getPrivates(user:String,progressBar: ProgressBar,callback: MyCallback,activity: SixthActivity){
        service.getPrivate(user)
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<List<Message>>(){
                    override fun onCompleted() {
                        logd("Completed getting private")
                        progressBar.visibility =View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while getting private messages")
                    }

                    override fun onNext(t: List<Message>?) {
                        Thread(Runnable {
                            logd("Saving privates messages to db")
                            app.db.messageDao.deleteMessages()
                            app.db.messageDao.addMessages(t!!)
                        }).start()
                    }
                })
    }

    fun deleteMessage(user:Message,progressBar: ProgressBar,callback: MyCallback,activity: SixthActivity){
        service.deleteMessage(user.id)
                .subscribeOn(Schedulers.newThread())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(object: Subscriber<Response<Any>>(){
                    override fun onCompleted() {
                        logd("Completed deleting")
                        progressBar.visibility =View.GONE
                    }

                    override fun onError(e: Throwable?) {
                        loge(e.toString())
                        callback.showError("An error has occured while deleting")
                    }

                    override fun onNext(t: Response<Any>?) {
                        Thread(Runnable {
                            logd("Delete from db")
                            app.db.messageDao.deleteMessage(user)
                        }).start()
                    }
                })
    }
    fun networkConnectivity(context: Context): Boolean {
        val cm = context
                .getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val networkInfo = cm.activeNetworkInfo
        return networkInfo != null && networkInfo.isConnected
    }
}