package com.example.ciprian.exam.adapters

import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ProgressBar
import com.example.ciprian.exam.*
import com.example.ciprian.exam.domain.Message
import kotlinx.android.synthetic.main.row_one.view.*
import kotlinx.android.synthetic.main.row_three.view.*


class ThirdAdapter: RecyclerView.Adapter<ThirdViewHolder>(){
    private var mValues = mutableListOf<Message>()
    var progressBar: ProgressBar? = null
    var application: MyApp? = null
    var callback: MyCallback? = null
    var activity: FourthActivity? = null

    fun setData(books: MutableList<Message>, progress: ProgressBar, app: MyApp, call: MyCallback, act: FourthActivity) {
        mValues.clear()
        mValues.addAll(books)
        progressBar = progress
        application = app
        callback = call
        activity = act
        notifyDataSetChanged()
    }
    fun setList(list:MutableList<Message>){
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

    override fun onBindViewHolder(holder: ThirdViewHolder, position: Int) {
        val item = mValues[position]
        val text = "Sender:"+item.sender+" Receiver:"+item.receiver+" Text:"+item.text+" Date:"+item.date + " Type:"+item.type
        holder.view.receiver_text.text = text
        holder.request = item


    }

    override fun onCreateViewHolder(parent: ViewGroup, p1: Int): ThirdViewHolder {
        var inflater = LayoutInflater.from(parent.context)
        var view = inflater.inflate(R.layout.row_three, parent, false)
        return ThirdViewHolder(view,null,this)
    }
}

class ThirdViewHolder(var view: View, var request:Any?, var adapter:ThirdAdapter): RecyclerView.ViewHolder(view){


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