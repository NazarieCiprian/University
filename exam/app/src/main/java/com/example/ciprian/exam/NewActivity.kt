package com.example.ciprian.exam

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View

import android.widget.Toast
import com.example.ciprian.exam.domain.Message
import kotlinx.android.synthetic.main.activity_new.*

class NewActivity : AppCompatActivity(),MyCallback {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_new)
        progressNew.visibility =View.GONE
        save_button.setOnClickListener{
            addMessage()
        }
    }

    override fun clear() {
        finish()
    }

    override fun showError(message: String) {
        progressNew.visibility =View.GONE
        Toast.makeText(this,message,Toast.LENGTH_SHORT).show()
    }
    fun addMessage(){
        try{
            progressNew.visibility = View.VISIBLE
            val sender = sender_controller.text.toString()
            val receiver = receiver_controller.text.toString()
            val text = text_controller.text.toString()
            val type = type_controller.text.toString()
            val msg = Message(0,sender,receiver,text,0,type)
            var manager = Manager(application as MyApp)
            manager!!.saveMessage(msg,progressNew,this,this)
        }catch (ex: Exception){
            showError(ex.toString())
        }
    }
}
