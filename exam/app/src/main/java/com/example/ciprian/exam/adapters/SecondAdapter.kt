package com.example.ciprian.exam.adapters

import android.content.Intent
import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ProgressBar
import android.widget.Toast
import com.example.ciprian.exam.*
import com.example.ciprian.exam.domain.Message
import kotlinx.android.synthetic.main.row_one.view.*
import kotlinx.android.synthetic.main.row_two.view.*


class SecondAdapter: RecyclerView.Adapter<SecondViewHolder>(){
    private var mValues = mutableListOf<String>()
    var progressBar: ProgressBar? = null
    var application: MyApp? = null
    var callback: MyCallback? = null
    var activity: ThirdActivity? = null

    fun setData(books: MutableList<String>, progress: ProgressBar, app: MyApp, call: MyCallback, act: ThirdActivity) {
        mValues.clear()
        mValues.addAll(books)
        progressBar = progress
        application = app
        callback = call
        activity = act
        notifyDataSetChanged()
    }
    fun setList(list:MutableList<String>){
        mValues.clear()
        mValues.addAll(list)
        notifyDataSetChanged()
        progressBar!!.visibility = View.GONE
    }

    fun clear() {
        mValues.clear()
        notifyDataSetChanged()
    }
    override fun getItemCount(): Int {
        return mValues.size
    }

    override fun onBindViewHolder(holder: SecondViewHolder, position: Int) {
        val item = mValues[position]
        //val text = "Sender:"+item.sender+" Receiver:"+item.receiver+" Text:"+item.text+" Date:"+item.date + " Type:"+item.type
        holder.view.user_text.text = item
        holder.request = item
        holder.view.sender_button.setOnClickListener{

            var manager = Manager(application as MyApp)
            if(manager.networkConnectivity(application!!.applicationContext)){
                val intent = Intent(holder.view.context, FourthActivity::class.java)
                intent.putExtra("name",item)
                holder.view.context.startActivity(intent)
            }else{
                Toast.makeText(application!!.applicationContext,"Not allowed offline",Toast.LENGTH_SHORT).show()
            }

        }

        holder.view.receiver_button.setOnClickListener{
            var manager = Manager(application as MyApp)
            if(manager.networkConnectivity(application!!.applicationContext)){
                val intent = Intent(holder.view.context, FifthActivity::class.java)
                intent.putExtra("name",item)
                holder.view.context.startActivity(intent)
            }else{
                Toast.makeText(application!!.applicationContext,"Not allowed offline",Toast.LENGTH_SHORT).show()
            }
        }


    }

    override fun onCreateViewHolder(parent: ViewGroup, p1: Int): SecondViewHolder {
        var inflater = LayoutInflater.from(parent.context)
        var view = inflater.inflate(R.layout.row_two, parent, false)
        return SecondViewHolder(view,null,this)
    }
}

class SecondViewHolder(var view: View, var request:Any?, var adapter:SecondAdapter): RecyclerView.ViewHolder(view){


    init {
//        view.setOnClickListener {
//            var manager = Manager(adapter.application!! as RateApp)
//            val intent = Intent(view.context, FourthActivity::class.java)
//            intent.putExtra("type",request!!.name)
//            if(manager.networkConnectivity(adapter.application!!.applicationContext)){
//                Toast.makeText(adapter.application!!.applicationContext, "You are online", Toast.LENGTH_SHORT).show()
//            }else{
//                Toast.makeText(adapter.application!!.applicationContext, "You are offline", Toast.LENGTH_SHORT).show()
//            }
//            view.context.startActivity(intent)
//        }
    }
}